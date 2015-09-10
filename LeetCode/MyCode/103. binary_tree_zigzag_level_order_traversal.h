#include <queue>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution103
{
public:
	vector<vector<int>> zigZag(TreeNode* root)
	{
		vector<vector<int>> res;
		if (!root)
			return res;
		queue<TreeNode*> zig;
		stack<TreeNode*> zag;
		zag.push(root);
		vector<int> row;
		row.push_back(root->val);
		res.push_back(row);
		int i = 0;
		while (!zag.empty())
		{
			i++;
			stack<TreeNode*> zag2;
			row.clear();
			while (!zag.empty())
			{
				if (i % 2 == 0)
				{
					if (zag.top()->left)
					{
						zag2.push(zag.top()->left);
						row.push_back(zag.top()->left -> val);
					}
					if (zag.top()->right)
					{
						row.push_back(zag.top()->right->val);
						zag2.push(zag.top()->right);
					}
				}
				else
				{
					if (zag.top()->right)
					{
						zag2.push(zag.top()->right);
						zag2.push(zag.top()->right);
					}
					if (zag.top()->left)
					{
						zag2.push(zag.top()->left);
						row.push_back(zag.top()->left->val);
					}
				}
				zag.pop();
			}
			zag = zag2;
			if (!row.empty())
				res.push_back(row);
		}
		return res;
	}
};