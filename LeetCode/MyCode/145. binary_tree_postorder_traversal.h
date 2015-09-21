#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//
//};
class Solution145
{
public:
	vector<int> postorderTraversal(TreeNode* root)
	{
		vector<int> res;
		if (!root)
			return res;
		stack<TreeNode*> s;
		s.push(root);
		unordered_set<TreeNode*> visited;
		while (!s.empty())
		{
			root = s.top();
			while (root->left&&visited.find(root->left) == visited.end())
			{
				s.push(root->left);
				root = root->left;
			}

			if (root->right&&visited.find(root->right) == visited.end())
			{
				s.push(root->right);
				root = root->right;

			}
			else if (visited.find(root) == visited.end())
			{
				res.push_back(root->val);
				visited.insert(root);
				s.pop();
			}
		}
		return res;
	}

	//这个也是从网上看到的，挺屌的，类似于先序遍历，只不过改成中-》右-》左，然后再逆序。
	vector<int> postorderTraversal2(TreeNode *root)
	{
		vector<int> rs;
		if (!root) return rs;  //若为空树，则返回空vector
		stack<TreeNode *> stk;
		stk.push(root);  //当前节点入栈
		while (!stk.empty())
		{
			TreeNode *t = stk.top();  //栈顶节点出栈、输出
			stk.pop();
			rs.push_back(t->val);
			//注意，下面入栈顺序不能错 ，因为先左后右，
			//这样出栈时先遍历才是右（中->右->左）
			if (t->left) stk.push(t->left);
			if (t->right) stk.push(t->right);
		}
		reverse(rs.begin(), rs.end());  //逆序，就成了后序遍历了
		return rs;
	}
};