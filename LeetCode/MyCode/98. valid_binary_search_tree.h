#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution98
{
public:
	bool isValidBST(TreeNode* root) {
		if (!root)
			return true;
		return (isValid(root->left, true) && isValid(root->right, false) && (!root->left || root->left->val < root->val) && (!root->right || root->right->val > root->val));

	}

	bool isValid(TreeNode* root, bool left)
	{
		if (!root)
			return true;
		if (isValid(root->left, true) && isValid(root->right, false) && (!root->left || root->left->val < root->val) && (!root->right || root->right->val > root->val))
		{
			if (left&&root->right)
			{
				TreeNode* temp = root;
				while (root->right)
				{
					temp->val = root->right->val;
					root = root->right;
				}
			}
			if (!left&&root->left)
			{
				TreeNode* temp = root;
				while (root->left)
				{
					temp->val = root->left->val;
					root = root->left;
				}
			}
			return true;
		}
		else
			return false;
	}

	//可以直接中序遍历，中序遍历的结果是递增的
	//这尼玛这么简洁，也是屌啊。
	TreeNode* pre = NULL;
	bool isValidBST2(TreeNode* root)
	{
		if (root)
		{
			if (!isValidBST2(root->left))
				return false;
			if (pre && pre->val >= root->val)
				return false;
			pre = root;
			
			return isValidBST2(root->right);
		
		}
		return true;
	}
};