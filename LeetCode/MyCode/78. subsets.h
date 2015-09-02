#include <vector>
using namespace std;

class Solution78
{
public:
	vector<vector<int>> subsets(vector<int>& nums)
	{
		vector<int> curr;
		vector<vector<int>> res;
		sort(nums.begin(), nums.end() - 1);
		for (int i = 0; i < nums.size(); i++)
		{
			add(nums.size(), i, 0, 0, curr, res,nums);
		}
		return res;
	}

	void add(int n, int k, int index, int deep, vector<int> curr, vector<vector<int>> &res, vector<int>& nums)
	{
		if (deep == k)
		{
			res.push_back(curr);
			return;
		}
		for (int i = index; i < n ; i++)
		{
			curr.push_back(nums[i]);
			add(n, k, i + 1, deep + 1, curr, res,nums);
			curr.pop_back();
		}
	}
};