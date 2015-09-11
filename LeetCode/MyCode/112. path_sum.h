#include <iostream>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution
{
public:
	bool hasPathSum(TreeNode* root, int sum)
	{
		path(root, 0, sum);
	}

	bool path(TreeNode* root, int curr, int sum)
	{
		if (!root)
			return false;
		curr += root->val;
		if (curr == sum)
			return true;
		if (path(root->left, curr, sum))
			return true;
		else
			return	path(root->right, curr, sum);
		
	}
};