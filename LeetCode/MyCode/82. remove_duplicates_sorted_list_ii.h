#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class Solution82
{
public:
	ListNode* deleteDuplicates(ListNode* head)
	{
		if (!head)
			return NULL;
		ListNode* res;
		ListNode* last = new ListNode(0);
		last->next = head;
		res = last;
		while (head->next)
		{
			bool del = false;
			while (head->next&&head->val == head->next->val)
			{
				//��¼�˽ڵ��Ƿ�Ҫɾ��
				del = true;
				head->next = head->next->next;
				
			}
			//ɾ���Ļ��ϸ��ڵ㲻��
			if (del)
				last->next = head->next;
			else //�������last���¸��ڵ�
			{
				last->next = head;
				last = head;
			}
			if (head->next)
			{
				head = head->next;
			}
		}
		return res->next;
	}
};