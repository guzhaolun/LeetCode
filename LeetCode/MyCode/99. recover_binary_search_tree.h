#include <iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

class Solution99
{
public:
	TreeNode* small = NULL;
	TreeNode* big = NULL;
	TreeNode* parent = NULL;
	void recoverTree(TreeNode* root)
	{
		find(root);
		swap(big->val, small->val);
	}

	void find(TreeNode* root)
	{
		if (!root)
			return;
		find(root->left);
		if (parent&&parent->val > root->val)
		{
			if (!big)
			{
				big = parent;
				small = root;
			}
			else
				small = root;
		}
		parent = root;
		find(root->right);
	}

	//中序遍历，依次存下，交换逆序的值
	void recoverTree2(TreeNode* root)
	{
		vector<TreeNode*> rec;
		record(root, rec);
		int start = 0, end = 0;
		bool flag = true;
		for (int i = 0; i < rec.size()-1&&flag; i++)
		{
			flag = false;
			for (int j = 0; j<rec.size() - i - 1;j++)

			if (rec[j]->val > rec[j + 1]->val)
			{
				swap(rec[j]->val, rec[j+1]->val);
				flag = true;
			}
		}
		
	}

	void record(TreeNode* root, vector<TreeNode*>& rec)
	{
		if (!root)
			return;
		record(root->left, rec);
		rec.push_back(root);
		record(root->right, rec);
	}
};