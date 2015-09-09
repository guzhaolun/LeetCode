#include <vector>
using namespace std;
//Definition for a binary tree node.
 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution95
{
public:
	vector<TreeNode*> generateTrees(int n)
	{
		return buildTree(1, n);
	}
	//动态规划，分别建立左右子树，选好根以后依次选取不同的子树。
	vector<TreeNode*> buildTree( int begin, int end)
	{
		vector<TreeNode*> res;
		TreeNode* root;
		if (begin > end)
		{
			res.push_back(NULL);
			return res;
		}
		vector<TreeNode*> leftTree;
		vector<TreeNode*> rightTree;
		for (int k = begin; k <= end; k++)
		{
			leftTree = buildTree(begin, k - 1);
			rightTree = buildTree(k + 1, end);
			for (int i = 0; i < leftTree.size(); i++)
			{
				for (int j = 0; j < rightTree.size(); j++)
				{
					root = new TreeNode(k);
					root->left = leftTree[i];
					root->right = rightTree[j];
					res.push_back(root);
				}
			}
		}
		return res;
	}
};