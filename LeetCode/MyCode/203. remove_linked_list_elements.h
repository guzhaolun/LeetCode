#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution203
{
public:
	ListNode* removeElements(ListNode* head, int val)
	{
		ListNode* res = new ListNode(0);
		ListNode* temp = res;
		temp->next = head;
		while (temp->next)
		{
			if (temp->next->val == val)
				temp->next = temp->next->next;
			else
				temp = temp->next;
		}
		return res->next;
	}
};