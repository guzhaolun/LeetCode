#include <vector>
using namespace std;

class Solution238
{
public:
	vector<int> productExceptSelf(vector<int>& nums)
	{
		vector<int> res;
		int last = 1;
		for (int i = 0; i < nums.size(); i++)
		{
			res.push_back(last);
			last *= nums[i];
		}
		last = 1;
		for (int i = nums.size() - 1; i >= 0; i--)
		{
			res[i] *= last;
			last *= nums[i];
		}
		return res;
	}
};