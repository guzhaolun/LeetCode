#include <iostream>
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
	//申请新的树
	TreeNode* invertTree(TreeNode* root) {
		if (!root)
			return NULL;
		TreeNode* newRoot = new TreeNode(root->val);
		recursive(root, newRoot);
		return newRoot;
	}

	void recursive(TreeNode* root1, TreeNode* root2)
	{
		if (!root1)
			return;
		if (!root1->left)
			root2->right = NULL;
		else if (!root2->right)
			root2->right = new TreeNode(root1->left->val);
		recursive(root1->left, root2->right);

		if (!root1->right)
			root2->left = NULL;
		else if (!root2->left)
			root2->left = new TreeNode(root1->right->val);
		recursive(root1->right, root2->left);
	}

	//不申请新的，感觉这个才是题目的要求。。
	TreeNode* invertTree2(TreeNode* root)
	{
		if (root == NULL)
			return NULL;
		TreeNode * ptmpNode = root->left;
		root->left = invertTree(root->right);
		root->right = invertTree(ptmpNode);
		return root;
	}
};