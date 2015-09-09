#include <vector>
#include <stack>
using namespace std;

 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution94
{
public:
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> res;
		stack<TreeNode*> tree;
		stack<bool> visited;
		if (!root)
			return res;

		while (1)
		{
			while (root)
			{
				tree.push(root);
				root = root->left;
			}
			if (tree.empty())
				break;
			root = tree.top();
			res.push_back(root->val);
			tree.pop();
			root = root->right;
		}
		return res;
	}
};