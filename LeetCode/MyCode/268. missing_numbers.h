#include <vector>
using namespace std;

class Solution268
{
public:
	//等差数列求和减去数组和就是，
	int missingNumber(vector<int>& nums)
	{
		int sum = 0;
		int i = 0;
		for (; i < nums.size(); i++)
		{
			sum += nums[i];
		}
		int diff = i*(i + 1) / 2 - sum;
		return diff;
	}

	//从0-n都异或两遍，缺失的那个异或了一遍
	int missingNumber2(vector<int>& nums)
	{
		int res = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			res ^= i;
			res ^= nums[i];
		}
		res ^= nums.size();
		return res;
	}
};