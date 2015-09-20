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
	bool hasCycle(ListNode *head) 
	{
		if (!head)
			return false;
		if (head->next == head)
			return true;

		ListNode* first = head->next;
		ListNode* second = head;
		while (first&&second)
		{
			if (first == second)
				return true;
			if (!first->next || !first->next->next)
				return false;
			first = first->next->next;
			second = second->next;
		}
		return false;
	}
};