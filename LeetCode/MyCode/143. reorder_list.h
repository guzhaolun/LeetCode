#include <iostream>
using namespace std;
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//	
//};

class Solution143
{
public:
	void reorderList(ListNode* head) 
	{
		if (!head || !head->next || !head->next->next)
			return;
		ListNode* begin = head;
		int count = 0;
		while (begin)
		{
			count++;
			begin = begin->next;
		}
		begin = head;
		int i = 0;
		ListNode* temp = head;
		while (i<count / 2)
		{
			temp = temp->next;
			i++;
		}
		ListNode* start = temp->next;
		ListNode* t;
		temp->next = NULL;
		while (start)
		{
			t = start->next;
			start->next = temp;
			temp = start;
			if (t)
				start = t;
			else
				break;
		}
		while (start->next)
		{
			temp = begin->next;
			t = start->next;
			begin->next = start;
			start->next = temp;
			start = t;
			begin = temp;
		}
	}
};