#include <vector>
#include <functional>
#include <queue>
using namespace std;
class Solution239
{
public:
	//window存递减的元素，每次删除尾部的较小的元素。
	//本来想着这个不是O(nk)的复杂度，后来一想，window里面存的只是有限个，肯定不会每次都pop k 次的。
	//最坏的情况是连续添加k个在pop个，平均下来还是O(n),也就是说每个元素最多进去一次出来一次。
	vector<int> maxSlidingWindow(vector<int>& nums, int k)
	{
		if (k<1 || nums.size()<k)
			return vector<int>();
		deque<int> d;
		vector<int> res;
		for (int i = 0; i<k; ++i)
		{
			while (!d.empty() && d.back()<nums[i])
				d.pop_back();
			d.push_back(nums[i]);
		}
		res.push_back(d.front());
		for (int i = k; i<nums.size(); ++i)
		{
			if (nums[i - k] == d.front())
				d.pop_front();
			while (!d.empty() && d.back()<nums[i])
				d.pop_back();
			d.push_back(nums[i]);
			res.push_back(d.front());
		}
		return res;
	}
};