#include <vector>
using namespace std;

class Solution189
{
public:
	void rotate(vector<int>& nums, int k)
	{
		int size = nums.size();
		if (k > size || k < 0)
			k %= size;
		reverse(nums.begin(), nums.begin() + size - k);
		reverse(nums.begin() + size - k, nums.end());
		reverse(nums.begin(), nums.end());
	}
};