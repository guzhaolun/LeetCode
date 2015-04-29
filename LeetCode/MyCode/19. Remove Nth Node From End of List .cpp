/**
* Definition for singly-linked list.
* 
*/
#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
}; class Solution {
public:
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		int step = 0;
		ListNode* head2 = head;
		ListNode* temp = head;
		ListNode* temp2 = head2;
		if (!head || !head->next&&n == 1)
			return NULL;
		while (head&&step<n - 1)
		{
			head = head->next;
			step++;
			if (step == n - 1)
				break;
		}
		if (head)
		{
			if (!head->next)
				return head2->next;
			while (head->next)
			{
				head = head->next;
				temp2 = head2;
				head2 = head2->next;
			}
		}
		else
			return NULL;
		temp2->next = head2->next;
		return temp;
	}
};