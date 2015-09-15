#include <vector>
#include <algorithm>
using namespace std;

class Solution123
{
public:
	//还是dp，左右两边同时找，然后取左边两边和的最大值，牛逼
	int maxProfit(vector<int>& prices)
	{
		if (prices.empty())
			return 0;
		int currMin = prices[0], currMax = prices[prices.size() - 1];
		int maxP = 0;
		vector<int> left(prices.size(), 0);
		vector<int> right(prices.size(), 0);
		for (int i = 1; i < prices.size(); i++)
		{
			currMin = min(currMin, prices[i]);
			left[i] = max(left[i-1], prices[i] - currMin);
		}

		for (int i = prices.size() - 2; i >= 0; i--)
		{
			currMax = max(currMax, prices[i]);
			right[i] = max(right[i + 1], currMax - prices[i]);
			maxP = max(maxP, left[i] + right[i]);
		}
		return maxP;
	}
};