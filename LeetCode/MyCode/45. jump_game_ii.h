#include <vector>
#include <algorithm>
using namespace std;

class Solution45
{
public:
	//妹的递归又超时了。。唉
	int jump(vector<int>& nums)
	{
		int minStep = INT_MAX;
		step(nums, 0, minStep,0);
		return minStep;
	}

	void step(vector<int>& nums, int index, int& minStep, int currStep)
	{
		currStep++;
		if (nums.size() - index - 1 <= nums[index])
		{
			if (currStep < minStep)
				minStep = currStep;
			return;
		}
		for (int i = nums[index]; i >=1; i--)
			step(nums, index + i, minStep, currStep);
	}

	//O(n)时间的，真是牛逼,类似于找最大连续子串和那个，记录下到每个位置的最大值就好了
	//证明：这个可以这么思考，如果i 是从i-1 跳到的，那么i位置的最少跳数 <i> = <i-1> +1.
	//如果i 是从i - 2  或之前跳到的，那么<i> = <i - 1>.
	//可以知道必定有<i> >= <i - 1>。
	int jump2(vector<int>& nums)
	{
		int res = 0;
		int curr = 0;
		int last = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (i>last)
			{
				last = curr;
				res++;
			}
			curr = max(curr, i + nums[i]);
		}
		return res;
	}
};