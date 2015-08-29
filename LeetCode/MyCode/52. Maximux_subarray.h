#include <vector>
using namespace std;

class Solution52
{
public:
	int maxSubArray(vector<int>& nums)
	{
		int res = INT_MIN;
		int curr = 0;
		//curr = nums[i];
		for (int i = 0; i < nums.size(); i++)
		{
			curr += nums[i];
			if (curr>res)
				res = curr;
			if (curr < 0)
				curr = 0;
		}
		return res;
	}
};