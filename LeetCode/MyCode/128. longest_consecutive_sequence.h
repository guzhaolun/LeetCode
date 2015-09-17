
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution128
{
public:
	//利用hash来做，unordered_set是hash原理，常数级访问。
	int longestConsecutive(vector<int>& nums)
	{
		unordered_set<int> curr;
		unordered_set<int> visited;
		if (nums.empty())
			return 0;
		int len = 0, maxLen = INT_MIN;
		for (int i = 0; i<nums.size(); i++)
			curr.insert(nums[i]);
		for (int i = 0; i < nums.size(); i++)
		{
			len = 1;
			if (visited.find(nums[i]) != visited.end())
				continue;
			int left = nums[i];
			while (curr.find(--left) != curr.end() && visited.find(left) == visited.end())
			{
				len++;
				visited.insert(left);
			}
			int right = nums[i];
			while (curr.find(++right) != curr.end() && visited.find(right) == visited.end())
			{
				len++;
				visited.insert(right);
			}
			maxLen = max(maxLen, len);
		}
		return maxLen;
	}
};