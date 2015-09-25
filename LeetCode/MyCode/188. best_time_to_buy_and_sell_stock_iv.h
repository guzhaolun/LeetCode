#include <vector>
using namespace std;

class Solution188
{
public:
	//此题好难。。不会
	//dp,O(kn);
	//http://segmentfault.com/a/1190000002565570
	int maxProfit(int k, vector<int>& prices)
	{
		int m = prices.size();
		
		int total = 0;
		if (k >= m / 2)
		{
			for (int i = 1; i < m; i++)
			{
				int t = prices[i] - prices[i - 1];
				total += t>0 ? t : 0;
			}
			return total;
		}
		vector<vector<int>> local(k + 1, vector<int>(m, 0));
		vector<vector<int>> globle(k + 1, vector<int>(m, 0));
		for (int i = 1; i <= k; i++)
		{
			for (int j = 1; j < m; j++)
			{
				int diff = prices[j] - prices[j - 1];
				local[i][j] = max(globle[i - 1][j - 1], local[i][j - 1] + diff);
				globle[i][j] = max(globle[i][j - 1], local[i][j]);
			}
		}
		return globle[k][m - 1];
	}

	//找出所有的（v1,p1),(v2,p2)对，O(n+klg(n))
	//https://leetcode.com/discuss/26745/c-solution-with-o-n-klgn-time-using-max-heap-and-stack
	//http://maskray.me/blog/2015-03-27-leetcode-best-time-to-buy-and-sell-stock-iv
	int maxProfit1(int k, vector<int>& prices)
	{
		int n = (int)prices.size(), ret = 0, v, p = 0;
		priority_queue<int> profits;
		stack<pair<int, int> > vp_pairs;
		while (p < n) {
			// find next valley/peak pair
			for (v = p; v < n - 1 && prices[v] >= prices[v + 1]; v++);
			for (p = v + 1; p < n && prices[p] >= prices[p - 1]; p++);
			// save profit of 1 transaction at last v/p pair, if current v is lower than last v
			while (!vp_pairs.empty() && prices[v] < prices[vp_pairs.top().first]) {
				profits.push(prices[vp_pairs.top().second - 1] - prices[vp_pairs.top().first]);
				vp_pairs.pop();
			}
			// save profit difference between 1 transaction (last v and current p) and 2 transactions (last v/p + current v/p),
			// if current v is higher than last v and current p is higher than last p
			while (!vp_pairs.empty() && prices[p - 1] >= prices[vp_pairs.top().second - 1]) {
				profits.push(prices[vp_pairs.top().second - 1] - prices[v]);
				v = vp_pairs.top().first;
				vp_pairs.pop();
			}
			vp_pairs.push(pair<int, int>(v, p));
		}
		// save profits of the rest v/p pairs
		while (!vp_pairs.empty()) {
			profits.push(prices[vp_pairs.top().second - 1] - prices[vp_pairs.top().first]);
			vp_pairs.pop();
		}
		// sum up first k highest profits
		for (int i = 0; i < k && !profits.empty(); i++) {
			ret += profits.top();
			profits.pop();
		}
		return ret;
	}
};