#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution92
{
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) 
	{

		ListNode *res=head,*cut, *begin, *end, *next;
		int i = 1;
		cut = NULL;
		begin = NULL;
		end = NULL;
		next = NULL;
		while (head)
		{
			if (i == m - 1)
				cut = head;
			if (i == m)
				begin = head;
			if (i == n)
			{
				end = head;
				break;
			}
			i++;
			head = head->next;
		}
		next = head->next;
		ListNode* it = begin->next;
		ListNode* last = begin;
		while (it&&it != next)
		{
			ListNode* n = it->next;
			it->next = last;
			last = it;
			it = n;
		}
		if (cut)
			cut->next = end;
		else
			res = end;
		begin->next = next;
		return res;
	}
};