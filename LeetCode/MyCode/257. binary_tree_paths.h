#include <vector>
#include <string>
using namespace std;
//Definition for a binary tree node.
// struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//	
//};

class Solution257 {
public:
	vector<string> binaryTreePaths(TreeNode* root) 
	{
		vector<string> res;
		if (!root)
			return res;
		string curr=to_string(root->val);
		path(root, curr, res);
		return res;
	}

	void path(TreeNode* root, string curr, vector<string>& res)
	{
		if (!root)
			return;
		if (!root->left&&!root->right)
		{
			res.push_back(curr);
			return;
		}
		if(root->left)
			path(root->left, curr+"->"+to_string(root->left->val), res);
		if(root->right)
			path(root->right, curr + "->" + to_string(root->right->val), res);
	}
};