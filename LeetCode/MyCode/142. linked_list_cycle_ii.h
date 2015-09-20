#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution
{
public:
	ListNode *detectCycle(ListNode *head)
	{
		if (!head)
			return NULL;
		if (head->next == head)
			return head;

		if (!head->next)
			return NULL;
		ListNode* first = head->next->next;
		ListNode* second = head->next;
		while (first&&second)
		{
			if (first == second)
			{
				second = head;
				break;
			}
			if (!first->next || !first->next->next)
				return NULL;
			first = first->next->next;
			second = second->next;
		}
		while (first&&second)
		{
			if (first == second)
				return first;
			first = first->next;
			second = second->next;
		}
		return NULL;
	}
};