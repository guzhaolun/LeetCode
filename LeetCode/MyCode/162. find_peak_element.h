#include <vector>
using namespace std;

class Solution162
{
public:
	int findPeakElement(vector<int>& nums)
	{
		if (nums.empty())
			return 0;
		if (nums.size() == 1)
			return 0;
		if (nums.size() == 2)
		{
			if (nums[0] > nums[1])
				return 0;
			else
				return 1;
		}
		if (nums[nums.size() - 1] > nums[nums.size() - 2])
			return nums.size() - 1;
		for (int i = 1; i < nums.size()-1; i++)
		{
			if (nums[i]>nums[i - 1] && nums[i] < nums[i + 1])
				return i;
		}
	}

	//�Ƚϴ������ٵģ���Ϊ��ͷ��С������������һ����iС��i+1����
	int findPeakElement2(vector<int>& nums)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			if (i + 1 < nums.size() && nums[i] > nums[i + 1])
				return i;
		}
		return nums.size() - 1;
	}

	//log(n)��, peak��Ȼ���ڡ����߶�С�����м��Ҿ����ˣ��۰롣
	int finPeakElement3(vector<int>& nums)
	{
		int left = 0, right = nums.size() - 1;
		while (left <= right)
		{
			if (left == right)
				return left;
			int mid = (left + right) / 2;
			if (nums[mid] < nums[mid + 1])
				left = mid + 1;
			else
				right = mid;
		}
	}
};