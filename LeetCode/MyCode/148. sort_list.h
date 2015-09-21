#include <iostream>
using namespace std;

//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//	
//};

class Solution148
{
public:
	//快排, 居然超时了,主要是pivot无法随机选取
	//http://blog.csdn.net/feliciafay/article/details/18921799
	//这边有解释，比较快排和归并排序，当用数组时由于快排不用申请空间，所以快排快，但是当用链表时插入比较复杂，pivot无法选取，就导致比较慢
	//快排最坏O（n^2)  http://blog.chinaunix.net/uid-21457204-id-3060260.html

	//但是还是不死心啊，然后继续找方案，结果发现一个好的，就是将重复的pivot直接加到pivot后面形成一个pivot链表，减少大量计算啊
	//最终ac了，速度还可以，前5%，有时间了试一下归并排序的。
	ListNode* sortList(ListNode* &head)
	{
		if (!head || !head->next)
			return head;
		ListNode* pivot_tail = head;
		ListNode* pivot = pivot_tail;
		ListNode* ltail = new ListNode(0);
		ltail->next = head;
		ListNode* lhead = ltail;
		ListNode* rhead=head;
		bool first = false;
		while (head&&head->next)
		{
			if (head->next->val < pivot_tail->val)
			{
				ltail->next = head->next;
				head->next = head->next->next;
				ltail = ltail->next;
			}
			else if (head->next->val == pivot_tail->val)
			{
				if (pivot_tail == head)
				{
					pivot_tail = head->next;
					head = head->next;
				}
				else
				{
					pivot_tail->next = head->next;
					head->next = head->next->next;
					pivot_tail = pivot_tail->next;
				}
			}
			else
			{
				if (!first)
				{
					rhead = head->next;
					first = true;
				}
				head = head->next;
			}
		}
		ltail->next = NULL;
		lhead=sortList(lhead->next);
		if (lhead)
		{
			ltail = lhead;
			while (lhead->next)
				lhead = lhead->next;
			lhead->next = pivot;
		}
		else
			ltail = pivot;
		if (first)
			pivot_tail->next = sortList(rhead);
		return ltail;
	}

};