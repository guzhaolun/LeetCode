#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution
{
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
	
		return build(preorder, inorder, 0, 0, inorder.size() - 1);
	}

	TreeNode* build(vector<int>& preorder, vector<int>& inorder, int rootIndex, int start, int end)
	{
		if (start>end)
			return NULL;
		if (rootIndex >= preorder.size())
			return NULL;
		TreeNode* root = new TreeNode(preorder[rootIndex]);
		for (int i = start; i <= end; i++)
		{
			if (inorder[i] == preorder[rootIndex])
			{

				root->left = build(preorder, inorder, rootIndex + 1, start, i - 1);

				root->right = build(preorder, inorder, rootIndex + i - start + 1, i + 1, end);
				//	rootIndex++;
				break;
			}
		}
		return root;
	}
};