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

	//���Ҳ�Ǵ����Ͽ����ģ�ͦ�ŵģ����������������ֻ�����ĳ���-����-����Ȼ��������
	vector<int> postorderTraversal2(TreeNode *root)
	{
		vector<int> rs;
		if (!root) return rs;  //��Ϊ�������򷵻ؿ�vector
		stack<TreeNode *> stk;
		stk.push(root);  //��ǰ�ڵ���ջ
		while (!stk.empty())
		{
			TreeNode *t = stk.top();  //ջ���ڵ��ջ�����
			stk.pop();
			rs.push_back(t->val);
			//ע�⣬������ջ˳���ܴ� ����Ϊ������ң�
			//������ջʱ�ȱ��������ң���->��->��
			if (t->left) stk.push(t->left);
			if (t->right) stk.push(t->right);
		}
		reverse(rs.begin(), rs.end());  //���򣬾ͳ��˺��������
		return rs;
	}
};