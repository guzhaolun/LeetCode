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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		int count = 0;
		ListNode* tempA = headA, *tempB = headB;
		while (tempA&&tempB)
		{
			tempA = tempA->next;
			tempB = tempB->next;
		}
		bool a = false;
		while (tempA)
		{
			tempA = tempA->next;
			count++;
		}
		while (tempB)
		{
			tempB = tempB->next;
			count++;
			a = true;
		}
		tempA = headA;
		tempB = headB;
		int i = 0;
		if (!a)
		{
			tempA = headB;
			tempB = headA;
		}
		while (i < count)
		{
			tempA = tempA->next;
			i++;
		}
		while (tempA&&tempB)
		{
			if (tempA == tempB)
				return tempA;
			else
			{
				tempA = tempA->next;
				tempB = tempB->next;
			}
		}
		return NULL;
	}
};