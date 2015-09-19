#include <iostream>
#include <unordered_map>
using namespace std;

//Definition for singly - linked list with a random pointer.
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}

};

class Solution
{
public:
	RandomListNode *copyRandomList(RandomListNode *head)
	{
		unordered_map<RandomListNode*, RandomListNode*> maps;
		if (!head)
			return NULL;
		RandomListNode* h = new RandomListNode(head->label);
		RandomListNode* res = h, *temp1 = head, *temp2 = h;
		maps[head] = h;
		head = head->next;
		while (head)
		{
			h->next = new RandomListNode(head->label);
			maps[head] = h->next;
			head = head->next;
			h = h->next;
		}
		while (temp1)
		{
			temp2->random = maps[temp1->random];
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		return res;
	}
};