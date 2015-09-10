#include <iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution100
{
public:
	bool isSameTree(TreeNode* p, TreeNode* q) 
	{
		if (!p&&!q)
			return true;
		if ((!p&&q) || (p&&!q))
			return false;
		if (isSameTree(p->left, q->left))
		{
			if (p->val != q->val)
				return false;
		}
		else
			return false;
		return	isSameTree(p->right, q->right);
	}
};