#include <vector>
using namespace std;

class Solution169
{
public:

	//除了用hash,自己没找到高效的。
	//这是别人的，找到不同的元素就成对删除，最后剩下的肯定是，太屌了。。。
	int majorityElement(vector<int>& nums)
	{
		int res;
		int count=0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (count == 0)
			{
				res = nums[i];
				count++;
			}
			else
			{
				if (nums[i] == res)
					count++;
				else
					count--;
			}
		}
		return res;
	}
};