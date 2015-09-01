#include <vector>
using namespace std;

class Solution75
{
public:

	//two scan
	void sortSolors(vector<int>& nums)
	{
		int colors[3] = { 0 };
		for (int i = 0; i < nums.size(); i++)
			colors[nums[i]]++;
		int index = 0;
		for (int i = 0; i < 3;i++)
		while (index<nums.size()&&(colors[i]--) != 0)
			 nums[index++]=i;
	}

	//one scan
	void sortColors2(vector<int>& nums)
	{
		int start = 0, end = nums.size() - 1;
		for (int i = 0; i <= end;)
		{
			if (nums[i] == 0)
				swap(nums[i++], nums[start++]);
			else if (nums[i] == 1)
					i++;
			else
				swap(nums[i], nums[end--]);
		}
	}

};