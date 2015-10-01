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
	//��ת��벿������
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
		//��������slow����ǰ��һ������벿��
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