#include <iostream>
using namespace std;
//Definition for binary tree with next pointer.
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
	
};

class Solution
{
public:
	void connect(TreeLinkNode *root)
	{
		TreeLinkNode* pre = new TreeLinkNode(0);
		if (!root)
			return;
		root->next = NULL;
		while (root&&root->left)
		{
			TreeLinkNode* temp = root->left;
			while (root)
			{
				pre->next = root->left;
				root->left->next = root->right;
				pre = root->right;
				root = root->next;
			}
			pre->next = NULL;
			if (temp->left)
			{
				pre = temp->left;
				root = temp;
			}
			else
				break;

		}
	}
};