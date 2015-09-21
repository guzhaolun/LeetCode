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
	//�տ�ʼ��֪����ô��¼�Ѿ����ʹ��ģ�Ȼ�����˸�set..
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

	//�������������·����ȷ��������ٷ��������ͺ���
	//��ʵ���в���ջ�Ľⷨ��O(1)�ռ䣬��������ָ�����Ƿ������������û�з��ʹ�
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