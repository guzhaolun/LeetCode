#include <vector>
#include <algorithm>
using namespace std;
class Solution287
{
public:
	//�������޸����顣�������ԾͲ������������Ǹ�Ҳ���С���
	int findDuplicate(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 1; i++)
		{
			if (nums[i] == nums[i + 1])
				return nums[i];
		}
	}

	//��ÿ�������ŵ����ڵ�λ���ϣ�������find first missing positive
	int findDuplicate2(vector<int>& nums)
	{
		if (nums.empty())return -1;
		for (int i = 0; i < nums.size(); i++)
		{
			while (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i])swap(nums[nums[i] - 1], nums[i]);
			if (nums[i] != i + 1)return nums[i];
		}
	}

	//�������飬�������в����� n / 2 �����ָ������� n / 2 �������ȷ��[1 - n / 2] ��Χ��һ���н⣬
	//�������ȷ��������(n / 2, n] ��Χ�ڡ�
	//�൱�ڴ�n����n/2�������⡣
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
	//����ָ�룬������Linked list cycle ii, nums[i]->nums[nums[i]]�γ�һ����������ڽڵ㡣
	//�������������ű��ˡ���
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