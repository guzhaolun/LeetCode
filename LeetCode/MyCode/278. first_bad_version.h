#include <algorithm>
using namespace std;
bool isBadVersion(int version);

class Solution278
{
public:
	int firstBadVersion(int n)
	{
		int left = 1, right = n;
		int bad = n;
		while (left <= right)
		{
			//int mid = (left + right) / 2;//如果用这个会超时，因为left+right越界了。。
			int mid = left + (right - left) / 2;
			if (isBadVersion(mid))
			{
				bad = min(bad, mid);
				right = mid - 1;
			}
			else
				left = mid + 1;
		}
		return bad;
	}
};