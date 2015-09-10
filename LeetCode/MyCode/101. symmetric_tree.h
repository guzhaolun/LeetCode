#include <iostream>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution101
{
public:
	bool isSymmetric(TreeNode* root)
	{
		if (!root)
			return true;
		compare(root->left, root->right);
	}

	bool compare(TreeNode* left, TreeNode* right)
	{
		if (!left&&!right)
			return true;
		if (!left&&right || left&&!right)
			return false;
		if (compare(left->left, right->right))
		{
			if (left->val != right->val)
				return false;
		}
		else
			return false;
		return compare(left->right, right->left);
	}
};