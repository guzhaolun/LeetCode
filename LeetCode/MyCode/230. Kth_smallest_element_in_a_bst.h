#include <iostream>
#include <stack>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution230
{
public:
	//�������
	//�ڽڵ���ά��������С��Ϣ��������O(h)
	int kthSmallest(TreeNode* root, int k)
	{
		int count = 0;
		stack<TreeNode*> s;
		//s.push(root);
		while (1)
		{
			while (root)
			{
				s.push(root);
				root = root->left;
			}
			if (s.empty())
				break;
			root = s.top();
			s.pop();
			count++;
			if (count == k)
				return root->val;
			root = root->right;
		}
	}

	int calcTreeSize(TreeNode* root){
		if (root == NULL)
			return 0;
		return 1 + calcTreeSize(root->left) + calcTreeSize(root->right);
	}

	//������һֱ���������Ĵ�С�����Ӷȸ������Ӧ��һ����
	int kthSmallest2(TreeNode* root, int k) {
		if (root == NULL)
			return 0;
		int leftSize = calcTreeSize(root->left);
		if (k == leftSize + 1){
			return root->val;
		}
		else if (leftSize >= k){
			return kthSmallest2(root->left, k);
		}
		else{
			return kthSmallest2(root->right, k - leftSize - 1);
		}
	}
};