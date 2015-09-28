#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> already;


		for (int i = 0; i<nums.size(); i++)
		{
			if (already.find(nums[i]) != already.end())
				return true;
			already.insert(nums[i]);
		}
		return false;
	}
};