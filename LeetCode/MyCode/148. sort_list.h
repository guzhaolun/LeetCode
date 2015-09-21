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
	//����, ��Ȼ��ʱ��,��Ҫ��pivot�޷����ѡȡ
	//http://blog.csdn.net/feliciafay/article/details/18921799
	//����н��ͣ��ȽϿ��ź͹鲢���򣬵�������ʱ���ڿ��Ų�������ռ䣬���Կ��ſ죬���ǵ�������ʱ����Ƚϸ��ӣ�pivot�޷�ѡȡ���͵��±Ƚ���
	//�����O��n^2)  http://blog.chinaunix.net/uid-21457204-id-3060260.html

	//���ǻ��ǲ����İ���Ȼ������ҷ������������һ���õģ����ǽ��ظ���pivotֱ�Ӽӵ�pivot�����γ�һ��pivot�������ٴ������㰡
	//����ac�ˣ��ٶȻ����ԣ�ǰ5%����ʱ������һ�¹鲢����ġ�
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