#include <unordered_map>
#include <vector>
using namespace std;

class Solution219
{
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k)
	{
		unordered_map<int, int> pos;
		for (int i = 0; i < nums.size(); i++)
		{
			if (pos.find(nums[i]) == pos.end())
				pos[nums[i]] = i;
			else
			{
				if (i - pos[nums[i]] <= k)
					return true;
				else
					pos[nums[i]] = i;
			}
		}
		return false;
	}
};