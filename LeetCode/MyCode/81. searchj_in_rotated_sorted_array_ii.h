#include <vector>
using namespace std;

class Solution81
{
public:
	bool search(vector<int>& nums, int target)
	{
		if (nums.empty())
			return false;
		int bound = 0;
		bool allasc = true;
		for (int i = 0; i < nums.size(); i++)
		{
			if (i + 1 < nums.size() && nums[i] > nums[i + 1])
			{
				allasc = false;
				bound = i;
				break;
			}
		}
		//�Ƿ��з�ת
		if (allasc)
			bound = nums.size() - 1;
		int low = 0, high = bound;
		if (nums[bound] < target)
			return false;
		if (nums[0] > target) //ȥ��벿����
		{
			low = bound+1;
			high = nums.size()- 1;
		}

		//����
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (nums[mid] == target)
				return true;
			else if (nums[mid]>target)
				high--;
			else
				low++;
		}

		return false;
	}
};