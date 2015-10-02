#include <iostream>
using namespace std;
/**
* Definition for singly-linked list.
**/ struct ListNode {
     int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		int num1 = 0, num2 = 0;
		int len = 0;
		ListNode* temp = new ListNode(0);
		ListNode* result = temp;
		for (; l1 != NULL&&l2 != NULL; l1 = l1->next, l2 = l2->next)
		{
			num1 = l1->val + l2->val + len;
			if (num1<10)
			{
				result->next = new ListNode(num1);
				result = result->next;
			}
			else
			{
				result->next = new ListNode(num1 % 10);
				result = result->next;

			}len = num1 / 10;
		}
		for (; l1 != NULL; l1 = l1->next)
		{
			num1 = l1->val + len;
			if (num1<10)
			{
				result->next = new ListNode(num1);
				result = result->next;
			}
			else
			{
				result->next = new ListNode(num1 % 10);
				result = result->next;

			} len = num1 / 10;

		}
		for (; l2 != NULL; l2 = l2->next)
		{
			num1 = l2->val + len;
			if (num1<10)
			{
				result->next = new ListNode(num1);
				result = result->next;
			}
			else
			{
				result->next = new ListNode(num1 % 10);
				result = result->next;

			} len = num1 / 10;
		}
		if (len == 1)
			result->next = new ListNode(1);
		return temp->next;
	}
};