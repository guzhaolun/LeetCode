#include <vector>
#include <algorithm>
using namespace std;

class Solution209
{
public:
	//一前一后两个指针，求中间的和。
	int minSubArrayLen(int s, vector<int>& nums)
	{
		if (nums.size() == 0)
			return 0;
		int sec = 0, first = 0;
		int total = 0;
		int len = INT_MAX;
		while (first < nums.size())
		{
			total += nums[first];
			if (total>=s)
			{
				len = min(len, first - sec + 1);
				total -= nums[sec];
				total -= nums[first];
				sec++;
			}
			else
				first++;
		}
		return len == INT_MAX ? 0 : len;
	}
};