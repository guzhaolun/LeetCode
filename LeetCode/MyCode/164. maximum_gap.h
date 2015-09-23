#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	//直接用hash来做的话超时了
	//其实直接快排可以过的。。
	int maximumGap(vector<int>& nums)
	{
		if (nums.size() < 2)
			return 0;
		unordered_set<int> sorted;
		int minv = INT_MAX;
		int maxv = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			minv = min(minv, nums[i]);
			maxv = max(maxv, nums[i]);
			sorted.insert(nums[i]);
		}
		int last = 0;
		int maxGap = 0;
		for (int i = minv; i < maxv;)
		{
			last = i;
			while (sorted.find(++i) == sorted.end())
				;
			maxGap = max(maxGap, i - last);
		}
		return maxGap;
	}
	/* 桶排序
	 *假设有N个元素A到B。
	 *
	 *	那么最大差值不会小于ceiling[(B - A) / (N - 1)]， 根据鸽巢原理。
	 *
	 *	令bucket（桶）的大小len = ceiling[(B - A) / (N - 1)]，则最多会有(B - A) / len + 1个桶
	 */
	int maximumGap(vector<int>& nums)
	{
		if (nums.size() < 2)
			return 0;
		int minAll = *min_element(nums.begin(), nums.end());
		int maxAll = *max_element(nums.begin(), nums.end());
		vector<int> min_bucket(nums.size(), INT_MAX);
		vector<int> max_bucket(nums.size(), INT_MIN);
		double gap = (double)(maxAll - minAll) / (nums.size() - 1);
		if (gap == 0)
			return 0;
		for (int i = 0; i < nums.size(); i++)
		{
			int id = (int)(nums[i] - minAll) / gap;
			min_bucket[id] = min(min_bucket[id], nums[i]);
			max_bucket[id] = max(max_bucket[id], nums[i]);
		}
		int res = 0;
		int pre = 0;
		for (int i = 1; i < nums.size(); i++)
		{
			if (min_bucket[i] != INT_MAX)
			{
				res = max(min_bucket[i] - max_bucket[pre], res);
				pre = i;
			}
		}
		return res;
	}
};