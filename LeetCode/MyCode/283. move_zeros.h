#include <vector>
using namespace std;

class Solution283
{
public:
	void moveZeroes(vector<int>& nums)
	{
		int pzero = nums.size(), pnonzero = nums.size();
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 0)
			{
				pzero = i;
				break;
			}
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != 0)
			{
				pnonzero = i;
				break;
			}
		}
		while (pzero < nums.size() && pnonzero < nums.size())
		{
			if (pzero<pnonzero&&nums[pnonzero] != 0)
				swap(nums[pzero], nums[pnonzero]);
			else
			{
				pnonzero++;
				continue;
			}
			pnonzero++;
			pzero++;
		}
	}

	//这够简洁。。
	void moveZeroes(vector<int>& nums) {
		for (auto i = nums.begin(), j = i; i != nums.end(); ++i)
		if (*i != 0)
			std::swap(*i, *j++);
	}

	void moveZeroes(vector<int>& nums)
	{
		int count = 0;
		int i = 0;
		for (; i < nums.size(); i++)
		{
			if (nums[i] == 0) 
			{
				count++;
			}
			if (nums[i] != 0 && count != 0)
			{
				nums[i - count] = nums[i];
				nums[i] = 0;
			}
		}
		for (i = i - count; i< nums.length; i++)
		{
			nums[i] = 0;
		}
	}
	//这几个时间测下来一样。。
	void moveZeroes(vector<int>& nums)
	{
		int p1 = 0, p2 = 0;
		while (p2 < nums.size())
		{

			if (p1 == p2)
			{
				if (nums[p1] != 0)
				{
					p1++;
				}
			}
			else
			{
				if (nums[p2] != 0)
				{
					nums[p1++] = nums[p2];
					nums[p2] = 0;
				}
			}
			p2++;
		}
	}
};