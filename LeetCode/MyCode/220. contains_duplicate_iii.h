#include <vector>
#include <algorithm>
using namespace std;
#include <unordered_map>
#include <set>
class Solution220
{
public:
	//����t��k�Ĵ�С��ѡ��ͬ��Ѱ�Ҳ��ԣ�����������Ǹ�����һ�����������о����ض����ݼ�����Ч����
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

	//set�Ǻ����ʵ�֣�����set�����ҿ�ܶࡣnlgk
	bool containsNearbyAlmostDuplicate2(vector<int>& nums, int k, int t) {
		multiset<long long> bst;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (bst.size() == k + 1) 
				bst.erase(bst.find(nums[i - k - 1]));
			auto lb = bst.lower_bound(nums[i] - t);//lower_bound��x����һ�����ڵ���x��Ԫ��
			if (lb != bst.end() && *lb - nums[i] <= t) 
				return true;
			bst.insert(nums[i]);
		}
		return false;
	}
};