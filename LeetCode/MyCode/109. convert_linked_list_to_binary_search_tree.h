#include <iostream>
using namespace std;

// Definition for singly - linked list.
 struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	TreeNode* sortedListToBST(ListNode* head)
	{
		int len = 0;
		ListNode* temp = head;
		while (head)
		{
			head = head->next;
			len++;
		}
		return	build(temp, 0 , len-1);
	}

	TreeNode* build(ListNode* &head, int start, int end)
	{
		if (start > end)
			return NULL;

		int mid = (end+start + 1) / 2;
		
		TreeNode* left = build(head, start,mid-1);
		TreeNode* root = new TreeNode(head->val);
		root->left = left;
		head = head->next;
		root->right = build(head, mid + 1, end);

		return root;
	}
};