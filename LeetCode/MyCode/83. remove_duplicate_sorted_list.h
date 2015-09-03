#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution83
{
public:
	ListNode* deleteDuplicates(ListNode* head)
	{
		if (!head)
			return NULL;
		ListNode* res = head;
		while (head->next)
		{
			while (head->next&&head->val == head->next->val)
				head->next = head->next->next;
			if (head->next)
				head = head->next;
		}
		return res;
	}
};