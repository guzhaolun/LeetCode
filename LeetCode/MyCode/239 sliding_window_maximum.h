#include <vector>
#include <functional>
#include <queue>
using namespace std;
class Solution239
{
public:
	//window��ݼ���Ԫ�أ�ÿ��ɾ��β���Ľ�С��Ԫ�ء�
	//���������������O(nk)�ĸ��Ӷȣ�����һ�룬window������ֻ�����޸����϶�����ÿ�ζ�pop k �εġ�
	//���������������k����pop����ƽ����������O(n),Ҳ����˵ÿ��Ԫ������ȥһ�γ���һ�Ρ�
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