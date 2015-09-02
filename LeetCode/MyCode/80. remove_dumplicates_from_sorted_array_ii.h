#include <vector>
using namespace std;

class Solution80
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			if (i + 1 < nums.size() && nums[i] == nums[i + 1])
			{
				i++;
			}
			while (i + 1 < nums.size() && nums[i] == nums[i + 1])
				nums.erase(nums.begin() + i + 1);
		}
		return nums.size();
	}
};