#include <vector>
#include <algorithm>
using namespace std;

class Solution122
{
public:
	int maxProfit(vector<int>& prices)
	{
		int currMin = INT_MAX;
		int maxP = 0;
		int total = 0;
		for (int i = 0; i < prices.size(); i++)
		{
			currMin = min(currMin, prices[i]);
			if (prices[i] - currMin>maxP)
			{
				total += prices[i] - currMin;
				maxP = 0;
				currMin = prices[i];
			}
			
		}
		return total;
	}
};