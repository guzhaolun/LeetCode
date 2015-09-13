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
		TreeLinkNode* temp = new TreeLinkNode(0);
		TreeLinkNode* pre = temp;
		if (!root)
			return;
		root->next = NULL;
		while (root)
		{
			pre = temp;
			while (root)
			{
				if (root->left)
				{
					pre->next = root->left;
					pre = root->left;
				}
				if (root->right)
				{
					pre->next = root->right;
					pre = root->right;
				}
				
				root = root->next;
			}
			pre->next = NULL;
			if (root->left)
			{
				root = root->left;
			}
			else if (root->right)
			{
				root = root->right;
			}
			else
				root = root->next;
		}
		delete[] temp;
	}
};