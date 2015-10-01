#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution235
{
public:
	//�տ�ʼ��Ϊ����ͨ�Ķ���������path��¼��·��
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		vector<TreeNode*> path1;
		vector<TreeNode*> path2;
		find(root, path1, p);
		find(root, path2, q);
		TreeNode* parent = root;
		int size = min(path1.size(), path2.size());
		for (int i = 0; i < size; i++)
		{
			if (path1[i] == path2[i])
				parent = path1[i];
		}
		return parent;
	}

	void find(TreeNode* root, vector<TreeNode*>& path, TreeNode* p)
	{
		path.push_back(root);
		if (root == p)
			return;
		if (p->val < root->val)
			find(root->left, path, p);
		else
			find(root->right, path, p);
	}

	//BST�Ļ�ֱ�ӱȽϽڵ��С������
	TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if (!root || !p || !q) return NULL;
		if (max(p->val, q->val) < root->val)
			return lowestCommonAncestor2(root->left, p, q);
		else if (min(p->val, q->val) > root->val)
			return lowestCommonAncestor2(root->right, p, q);
		else
			return root;
	}
};