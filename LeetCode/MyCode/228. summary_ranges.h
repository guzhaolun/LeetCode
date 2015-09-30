#include <vector>
#include <string>
using namespace std;
class Solution228
{
public:
	vector<string> summaryRanges(vector<int>& nums)
	{
		vector<string> res;
		string s;
		for (int i = 0; i < nums.size(); i++)
		{
			int temp = i;
			s = to_string(nums[i]);
			
			if (i + 1 < nums.size() && nums[i] + 1 == nums[i + 1])
			{
				i++;
			}
			if (i>temp)
				s += "->";
			s += to_string(nums[i]);
			res.push_back(s);
		}
		return res;
	}
};