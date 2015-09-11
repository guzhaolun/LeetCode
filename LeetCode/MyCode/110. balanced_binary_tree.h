#include <iostream>
#include <algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution 
{
public:
	bool isBalanced(TreeNode* root)
	{
		bool res = true;
		height(root, res);
		return res;
	}

	int height(TreeNode* root, bool &res)
	{
		if (!root)
			return 0;
		int leftH = height(root->left, res);
		int rightH = height(root->right, res);
		if (abs(leftH - rightH) > 1)
		{
			res = false;
			return 0;
		}
		return max(leftH, rightH) + 1;
	}
};