#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
class Solution206
{
public:
	ListNode* reverseList(ListNode* head)
	{
		ListNode* temp;
		ListNode* t;
		if (!head)
			return NULL;
		temp = head->next;
		head->next = NULL;
		while (temp)
		{
			t = temp->next;
			temp->next = head;
			head = temp;
			temp = t;
		}
		return head;
	}
};