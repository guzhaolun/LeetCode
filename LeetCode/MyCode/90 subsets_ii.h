#include <vector>
#include <algorithm>
using namespace std;

class Solution90
{
public:
	vector<vector<int>> subsets(vector<int>& nums)
	{
		vector<int> curr;
		vector<vector<int>> res;
		sort(nums.begin(), nums.end() );
		for (int i = 0; i < nums.size()+1; i++)
		{
			add(nums.size(), i, 0, 0, curr, res, nums);
		}
		return res;
	}
	//递归，回溯
	//最后那个while循环真是精髓，出栈以后再跳过重复的，这样前面入栈的就不会受到影响。
	void add(int n, int k, int index, int deep, vector<int> curr, vector<vector<int>> &res, vector<int>& nums)
	{
		if (deep == k)
		{
			res.push_back(curr);
			return;
		}
		for (int i = index; i < n; i++)
		{
			curr.push_back(nums[i]);
			add(n, k, i + 1, deep + 1, curr, res, nums);
			curr.pop_back();
			while (i < n - 1 && nums[i] == nums[i + 1])
				i++;
		}
	}
};