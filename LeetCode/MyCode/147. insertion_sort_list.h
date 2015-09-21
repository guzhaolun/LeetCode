#include <iostream>
using namespace std;
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//	
//};

class Solution147
{
public:
	ListNode* insertionSortList(ListNode* head) 
	{
		if (!head)
			return NULL;
		ListNode* pre = head;
		ListNode* it = head;
		ListNode* res = NULL;
		ListNode* r = new ListNode(0);
		ListNode* temp = r;
		int curr = head->val;
		r->next = head;
		it = head;
		while (it->next)
		{
			bool found = false;
			while (it->next)
			{
				if (it->next->val < curr)
				{
					res = it->next;
					pre = it;
					curr = it->next->val;
					found = true;
				}
				it = it->next;
			}
			if (found)
			{
				pre->next = res->next;
				r->next = res;
				res->next = head;
				curr = head->val;
			}
			else
				curr = r->next->next->val;
			r = r->next;
			it = r->next;
			head = r->next;
		}
		return temp->next;
	}

	//重新建表，依次插入合适的节点。
	ListNode *insertionSortList2(ListNode *head)
	{
		if (head == NULL || head->next == NULL) return head;
		ListNode *cur = head;
		ListNode *helper = new ListNode(0);
		ListNode *pre;
		while (cur)
		{
			ListNode *next = cur->next;
			pre = helper;
			while (pre->next != NULL && pre->next->val<cur->val)
			{
				pre = pre->next;
			}
			cur->next = pre->next;
			pre->next = cur;
			cur = next;
		}
		return helper->next;
	}
};