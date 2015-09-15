#include <iostream>
#include <algorithm>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
public:

	//刚开始从上往下每个节点遍历，超时了
	//修改后后序遍历，从下往上记录最好结果，dp
	int maxPathSum(TreeNode* root)
	{
		if (!root)
			return 0;
		int currMax = INT_MIN;
		int left = 0, right = 0;
		allPath(root, currMax, left);
		return currMax;
	}

	void allPath(TreeNode* root, int &currMax, int& pathMax)
	{
		if (!root)
			return;
		int left = 0;
		int right = 0;
		allPath(root->left, currMax, left);
		allPath(root->right, currMax, right);
		currMax = max(currMax, right + root->val);
		currMax = max(currMax, left + root->val);
		currMax = max(currMax, left + root->val + right);
		left = max(root->val, left + root->val);
		right = max(root->val, right + root->val);
		pathMax = max(left, right);
		pathMax = max(0, pathMax);
	}
};