#include <iostream>
using namespace std;
/**
* Definition for singly-linked list.
*/
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution61 
{
public:
	ListNode* rotateRight(ListNode* head, int k)
	{
		ListNode* p1 = head;
		ListNode* p2 = head;
		if (head == NULL)
			return NULL;

		int n = 1;
		ListNode* temp = head;
		while (temp->next)
		{
			temp = temp->next;
			n++;
		}
		int i = 0;
		while (p1->next != NULL)
		{
			i++;
			p1 = p1->next;
			if (i > k%n)
				p2 = p2->next;
		}
		if (i < k%n)
			return head;
		p1->next = head;
		head = p2->next;
		p2->next = NULL;
		return head;
	}
};