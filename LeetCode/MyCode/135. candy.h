#include <vector>
#include <algorithm>
using namespace std;

class Solution135
{
public:
	//从最小的向两边扩展，大的覆盖小的，O(n)
	int candy(vector<int>& ratings)
	{
		int size = ratings.size();
		vector<int> res(size, 0);
		int left = 0, right = 1;
		for (int i = 0; i < size;)
		{
			while (i + 1 < size&&ratings[i] > ratings[i + 1])
				i++;
			res[i] = 1;
			left = i - 1;
			while (left >= right - 1 && ratings[left]>ratings[left + 1])
				res[left--] = max(res[left + 1], res[left + 2] + 1);
			right = i + 1;
			while (right < size&&ratings[right]>ratings[right - 1])
				res[right++] = res[right - 2] + 1;
			i = right;
		}
		int total = 0;
		for (int i = 0; i < size; i++)
		{
			total += res[i];
		}
		return total;
	}
};