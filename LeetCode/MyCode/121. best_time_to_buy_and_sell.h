#include <vector>
#include <algorithm>
using namespace std;

class Solution121
{
public:
	int maxProfit(vector<int>& prices)
	{
		int currMin = INT_MAX;
		int maxP = 0;
		for (int i = 0; i < prices.size(); i++)
		{
			currMin = min(currMin, prices[i]);
			maxP = max(maxP, prices[i] - currMin);
		}
		return maxP;
	}
};