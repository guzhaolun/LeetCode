#include <vector>
#include <queue>
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
	//按层次遍历即可，每层获得最后一个元素
	vector<int> rightSideView(TreeNode* root)
	{
		queue<TreeNode*> odd;
		
		vector<int> res;
		while (!root)
			return res;
		odd.push(root);
		res.push_back(root->val);
		while (!odd.empty())
		{
			queue<TreeNode*> even;
			while (!odd.empty())
			{
				TreeNode* t = odd.front();
				if (t->left)
					even.push(t->left);
				if (t->right)
					even.push(t->right);
				odd.pop();
			}
			if (even.empty())
				return res;
			res.push_back(even.back()->val);
			odd = even;
		}
		return res;
	}
};