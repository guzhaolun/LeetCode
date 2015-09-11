#include <vector>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution
{
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
	{
		return build(postorder, inorder, postorder.size()-1, 0, inorder.size() - 1);
	}

	TreeNode* build(vector<int>& postorder, vector<int>& inorder, int rootIndex, int start, int end)
	{
		if (start > end)
			return NULL;
		if (rootIndex <0 )
			return NULL;
		TreeNode* root = new TreeNode(postorder[rootIndex]);
		for (int i = start; i <= end; i++)
		{
			if (inorder[i] == postorder[rootIndex])
			{
				root->right = build(postorder, inorder, rootIndex-1, i + 1, end);
				root->left = build(postorder, inorder, rootIndex-end+i-1, start, i - 1);
				
				break;
			}
		}
		return root;
	}
};