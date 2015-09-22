#include<vector>
using namespace std;
class Solution153
{
public:
	int finMin(vector<int>& nums)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			if (i + 1 < nums.size() && nums[i] > nums[i + 1])
				return nums[i + 1];
		}
		return nums[0];
	}
};