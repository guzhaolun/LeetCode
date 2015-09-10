#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution102
{
public:
	vector<vector<int>> levelOrder(TreeNode* root) 
	{
		queue<TreeNode*> tree;
		tree.push(root);
		vector<vector<int>> res;
		if (!root)
			return res;
		vector<int> a;
		a.push_back(root->val);
		res.push_back(a);
		while (!tree.empty())
		{
			queue<TreeNode*> tree2;
			vector<int> row;
			while (!tree.empty())
			{
				TreeNode* temp = tree.front();
				tree.pop();
				if (temp->left)
				{
					row.push_back(temp->left->val);
					tree2.push(temp->left);
				}
				if (temp->right)
				{
					row.push_back(temp->right->val);
					tree2.push(temp->right);
				}
			}
			res.push_back(row);
			tree = tree2;
		}
		return res;
	}
};