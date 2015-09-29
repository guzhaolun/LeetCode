#include <vector>
#include <algorithm>
using namespace std;
#include <unordered_map>
#include <set>
class Solution220
{
public:
	//根据t和k的大小来选择不同的寻找策略，结果比下面那个还快一倍。。不过感觉对特定数据集才有效。。
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
	{
		unordered_map<int, int> pos;
		long long temp;
		if (k == 0)
			return false;
		for (int i = 0; i < nums.size(); i++)
		{

			if (t <= 10000)
			{
				for (int j = nums[i] - t; j <= nums[i] + t; j++)
				if (pos.find(j) != pos.end() && (i - pos[j]) <= k)
					return true;
			}
			else{
				for (int j = max(0, i - k); j < i; j++)
				{
					temp = nums[i] - nums[j];
					if (abs(temp) <= t)
						return true;
				}
			}
			pos[nums[i]] = i;

		}
		return false;
	}

	//set是红黑树实现，利用set来查找快很多。nlgk
	bool containsNearbyAlmostDuplicate2(vector<int>& nums, int k, int t) {
		multiset<long long> bst;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (bst.size() == k + 1) 
				bst.erase(bst.find(nums[i - k - 1]));
			auto lb = bst.lower_bound(nums[i] - t);//lower_bound（x）第一个大于等于x的元素
			if (lb != bst.end() && *lb - nums[i] <= t) 
				return true;
			bst.insert(nums[i]);
		}
		return false;
	}
};