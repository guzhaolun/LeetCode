#include <vector>
using namespace std;

class Solution46
{
public:
	vector<vector<int>> permute2(vector<int>& nums)
	{
		vector<vector<int>> res;
		compute(nums, res,0);
		return res;
	}

	bool isDuplicates(vector<int>& nums, int begin, int end)
	{
		for (int i = begin; i < end; i++)
		{
			if (nums[i] == nums[end])
				return false;
		}
		return true;
	}
	void compute(vector<int>& nums, vector<vector<int>>& res, int index)
	{
		if (index == nums.size())
			res.push_back(nums);

		for (int i = index; i < nums.size(); i++)
		{
			if (isDuplicates(nums, index+1, i))
			{
				swap(nums[index], nums[i]);
				compute(nums, res, index + 1);
				swap(nums[index], nums[i]);
			}
		}
	}

	void swap(int &a, int &b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
};