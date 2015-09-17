#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution129
{
public:
	int sumNumbers(TreeNode* root)
	{
		vector<int> nums;
		int sum = 0;
		path(root, nums, sum);
		return sum;
	}

	void path(TreeNode* root, vector<int> nums, int& sum)
	{
		if (!root)
			return;
		nums.push_back(root->val);
		if (!root->left&&!root->right)
		{
			for (int i = 0; i < nums.size(); i++)
				sum += nums[i] * pow(10, nums.size() - i - 1);
		}
		path(root->left, nums, sum);
		path(root->right, nums, sum);
	}
};