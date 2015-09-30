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
	//中序遍历
	//在节点中维护子树大小信息可以做到O(h)
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

	//这种是一直计算子树的大小，复杂度跟上面的应该一样。
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