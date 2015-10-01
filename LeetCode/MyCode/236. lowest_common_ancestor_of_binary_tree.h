#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Definition for a binary tree node.
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//
//};

class Solution236
{
public:
	//��������Ѱ�ң���path��¼·��
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

	bool find(TreeNode* root, vector<TreeNode*>& path, TreeNode* p)
	{
		if (!root)
		{
			return false;
		}
		path.push_back(root);
		if (root == p)
			return true;
		if (find(root->left, path, p))
			return true;
		else
		if (find(root->right, path, p))
		{
			return true;
		}
		path.pop_back(); 
		return false;
	}

	//�ڵ�a��ڵ�b�Ĺ�������cһ�����㣺a��b�ֱ������c�����������ϣ����a����b���������ȵĻ�����
	TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) 
	{
		if (root == NULL) return NULL;
		if (root == p || root == q) return root;
		TreeNode *L = lowestCommonAncestor2(root->left, p, q);
		TreeNode *R = lowestCommonAncestor2(root->right, p, q);
		if (L && R) return root;
		return L ? L : R;

	}
};