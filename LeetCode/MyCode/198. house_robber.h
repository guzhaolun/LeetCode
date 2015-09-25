#include <vector>
#include <algorithm>
using namespace std;

class Solution198
{
public:
	//dp,当前房子抢或者不抢。
	int rob(vector<int>& nums)
	{
		int size = nums.size();
		vector<int> dp(size, 0);
		if (size == 0)
			return 0;
		if (size == 1)
			return nums[0];
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		for (int i = 2; i < size; i++)
		{
			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
		}
		return dp[size - 1];
	}
};