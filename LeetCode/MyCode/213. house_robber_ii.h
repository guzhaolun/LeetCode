#include <vector>
#include <algorithm>
using namespace std;

class Solution213 {
public:
	//dp，分两种，一种包括0，但不包括size-1;一种不包括0，包括size-1;
	int rob(vector<int>& nums) {
		int size = nums.size();
		int maxv = 0;
		vector<int> dp(size, 0);
		if (size == 0)
			return 0;
		if (size == 1)
			return nums[0];
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		for (int i = 2; i < size - 1; i++)
		{
			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
		}
		maxv = dp[size - 2];

		dp.clear();
		dp[0] = 0;
		dp[1] = nums[1];
		for (int i = 2; i < size; i++)
		{
			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
		}

		maxv = max(maxv, dp[size - 1]);
		return maxv;
	}
};