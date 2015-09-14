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
		TreeLinkNode* next = root;
		TreeLinkNode* pre = temp;
		if (!root)
			return;
		root->next = NULL;
		while (root)
		{
			pre = temp;
			bool findNext = false;
			while (root)
			{
				if (root->left)
				{
					pre->next = root->left;
					pre = root->left;
					if (!findNext)
					{
						next = root->left;
						findNext = true;
					}
				}
				if (root->right)
				{
					pre->next = root->right;
					pre = root->right;
					if (!findNext)
					{
						next = root->right;
						findNext = true;
					}
				}

				root = root->next;
			}
			pre->next = NULL;
			if (findNext)
				root = next;
			else break;
		}
		delete[] temp;
	}
};