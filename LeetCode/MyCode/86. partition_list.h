#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution86
{
public:
	ListNode* partition(ListNode* head, int x)
	{
		ListNode* smallH = new ListNode(0);
		ListNode* largeH = new ListNode(0);
		ListNode* smallE = smallH;
		ListNode* largeE = largeH;
		while (head)
		{
			if (head->val < x)
			{
				smallE->next = head;
				smallE = head;
				head = head->next;
			}
			else
			{
				largeE->next = head;
				largeE = head;
				head = head->next;
			}
		}
		largeE->next = NULL;
		smallE->next = largeH->next;
		return smallH->next;
	}
};