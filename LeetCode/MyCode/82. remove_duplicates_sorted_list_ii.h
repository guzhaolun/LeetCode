#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class Solution82
{
public:
	ListNode* deleteDuplicates(ListNode* head)
	{
		if (!head)
			return NULL;
		ListNode* res;
		ListNode* last = new ListNode(0);
		last->next = head;
		res = last;
		while (head->next)
		{
			bool del = false;
			while (head->next&&head->val == head->next->val)
			{
				//记录此节点是否要删除
				del = true;
				head->next = head->next->next;
				
			}
			//删除的话上个节点不变
			if (del)
				last->next = head->next;
			else //否则更新last到下个节点
			{
				last->next = head;
				last = head;
			}
			if (head->next)
			{
				head = head->next;
			}
		}
		return res->next;
	}
};