#include <vector>
#include <stack>
#include <unordered_set>
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
	//刚开始不知道怎么记录已经访问过的，然后用了个set..
	vector<int> preorderTraversal(TreeNode* root)
	{
		vector<int> res;
		if (!root)
			return res;
		stack<TreeNode*> s;
		s.push(root);
		unordered_set<TreeNode*> visited;
		visited.insert(root);
		res.push_back(root->val);
		visited.insert(root);
		while (!s.empty())
		{
			TreeNode* temp = s.top();
			if (visited.find(temp) == visited.end())
			{
				res.push_back(temp->val);
				visited.insert(temp);
			}
			if (temp->left&&visited.find(temp->left) == visited.end())
				s.push(temp->left);
			else if (temp->right&&visited.find(temp->right) == visited.end())
				s.push(temp->right);
			else
				s.pop();
		}
		return res;
	}

	//后来网上搜了下发现先放右子树再放左子树就好了
	//其实还有不用栈的解法，O(1)空间，利用两个指针来是否相等来代表有没有访问过
	vector<int> preorderTraversal(TreeNode* root)
	{
		vector<int> res;
		if (!root)
			return res;
		stack<TreeNode*> s;
		s.push(root);
		while (!s.empty())
		{
			TreeNode* temp = s.top();
			s.pop();
			res.push_back(temp->val);
			if (temp->right)
				s.push(temp->right);
			if (temp->left)
				s.push(temp->left);
		}
		return res;
	}
};