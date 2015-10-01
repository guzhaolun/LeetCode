#include <iostream>
using namespace std;
//Definition for singly - linked list.
 struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution234
{
public:
	//反转后半部分链表
	bool isPalindrome(ListNode* head)
	{
		ListNode* old = head;
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast&&fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		//奇数个，slow再向前走一步到后半部分
		if (fast)
		{
			ListNode* temp = slow;
			slow = slow->next;
			temp->next = NULL;
		}
		ListNode* last = NULL;
		while (slow)
		{
			ListNode* temp = slow->next;
			slow->next = last;
			last = slow;
			slow = temp;
		}
		while (last)
		{
			if (last->val != old->val)
				return false;
			last = last->next;
			old = old->next;
		}
		return true;
	}
};