#include <vector>
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
	vector<vector<int>> pathSum(TreeNode* root, int sum)
	{
		vector<int> curr;
		vector<vector<int>> res;
		path(root, 0, sum, curr, res);
		return res;
	}

	void path(TreeNode* root, int curr, int sum,vector<int> currSum, vector<vector<int>>& res)
	{
		if (!root)
			return ;
		curr += root->val;
		currSum.push_back(root->val);
		if (curr == sum && (!root->left&&!root->right))
			res.push_back(currSum);
		path(root->left, curr, sum, currSum, res);
		path(root->right, curr, sum, currSum, res);

	}
};