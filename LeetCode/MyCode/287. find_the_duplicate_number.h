#include <vector>
#include <algorithm>
using namespace std;
class Solution287
{
public:
	//不允许修改数组。。。所以就不能排序，下面那个也不行。。
	int findDuplicate(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 1; i++)
		{
			if (nums[i] == nums[i + 1])
				return nums[i];
		}
	}

	//把每个数都放到该在的位置上，类似于find first missing positive
	int findDuplicate2(vector<int>& nums)
	{
		if (nums.empty())return -1;
		for (int i = 0; i < nums.size(); i++)
		{
			while (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i])swap(nums[nums[i] - 1], nums[i]);
			if (nums[i] != i + 1)return nums[i];
		}
	}

	//遍历数组，若数组中不大于 n / 2 的数字个数超过 n / 2 ，则可以确定[1 - n / 2] 范围内一定有解，
	//否则可以确定解落在(n / 2, n] 范围内。
	//相当于从n降到n/2的子问题。
	int findDuplicate3(vector<int>& nums)
	{
		int l = 0, r = nums.size() - 1, m;
		while (l <= r) 
		{
			m = l + ((r - l) >> 1);
			int cnt = 0;
			for (auto a : nums) 
				if (a <= m) 
					++cnt;
			if (cnt <= m) l = m + 1;
			else r = m - 1;
		}
		return l;
	}

	//https://leetcode.com/discuss/61514/understood-solution-space-without-modifying-explanation
	//快慢指针，类似于Linked list cycle ii, nums[i]->nums[nums[i]]形成一个链表，找入口节点。
	//这联想能力，屌爆了。。
	int findDuplicate3(vector<int>& nums)
	{
		if (nums.size() > 1)
		{
			int slow = nums[0];
			int fast = nums[nums[0]];
			while (slow != fast)
			{
				slow = nums[slow];
				fast = nums[nums[fast]];
			}

			fast = 0;
			while (fast != slow)
			{
				fast = nums[fast];
				slow = nums[slow];
			}
			return slow;
		}
		return -1;
	}
};