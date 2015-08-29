#include <vector>
using namespace std;

class Solution54
{
public:
	bool canJump(vector<int>& nums)
	{
		bool can = false;
		for (int i = 0; i < nums.size()-1; i++)
		{
			if (nums[i] == 0)
			{
				for (int j = 0; j < i; j++)
				{
					if (i - j < nums[j])
						can = true;
				}
				if (!can)
					return false;
			}
		}
		return can;
	}
};