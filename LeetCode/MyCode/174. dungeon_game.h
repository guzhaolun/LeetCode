#include <vector>
#include <algorithm>
using namespace std;

class Solution174
{
public:
	//从左上角到右下角，发现不行。。因为需要考虑当前血量和之前最少血量两个因素，碰到[[1,-3,3],[0,-2,0],[-3,-3,-3]]这种case就算错了。
	int calculateMinimumHP(vector<vector<int>>& dungeon)
	{
		if (dungeon.empty())
			return 0;
		int m = dungeon.size();
		int n = dungeon[0].size();
		vector<vector< pair<int, int>>>dp(m, vector<pair<int, int>>(n, make_pair(0, 0)));
		dp[0][0].first = dungeon[0][0];
		dp[0][0].second = dungeon[0][0];
		for (int i = 1; i < m; i++)
		{
			dp[i][0].first = dp[i - 1][0].first + dungeon[i][0];
			dp[i][0].second = min(dp[i][0].first, dp[i-1][0].second);
		}

		for (int i = 1; i < n; i++)
		{
			dp[0][i].first = dp[0][i - 1].first + dungeon[0][i];
			dp[0][i].second = min(dp[0][i].first, dp[0][i-1].second);
		}

		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				if (dp[i - 1][j].second > dp[i][j - 1].second)
				{
					dp[i][j].first = dp[i - 1][j].first + dungeon[i][j];
					dp[i][j].second = min(dp[i - 1][j].second, dp[i][j].first);
				}
				else if (dp[i - 1][j].second < dp[i][j - 1].second)
				{
					dp[i][j].first = dp[i][j - 1].first + dungeon[i][j];
					dp[i][j].second = min(dp[i][j - 1].second, dp[i][j].first);
				}
				else
				{
					dp[i][j].first = dp[i][j - 1].first + dungeon[i][j];
					dp[i][j].second = min(dp[i][j - 1].second, dp[i - 1][j].second) + dungeon[i][j];
				}
			}
		}
		if (dp[m - 1][n - 1].second > 0)
			return 0;
		else
			return 0 - dp[m - 1][n - 1].second + 1;
	}

	//换个思路，从右下到左上, 直接记录需要的最少血量就好，AC
	int calculateMinimumHP2(vector<vector<int>>& dungeon)
	{
		if (dungeon.empty())
			return 0;
		int m = dungeon.size();
		int n = dungeon[0].size();
		vector<vector<int>> dp(m, vector<int>(n, 0));

		dp[m - 1][n - 1] = dungeon[m - 1][n - 1] > 0 ? 1 : 1 - dungeon[m - 1][n - 1];
		for (int i = m - 2; i >= 0; i--)
		{
			int t = dp[i + 1][n - 1]-dungeon[i][n - 1]  ;
			dp[i][n - 1] = t > 0 ? t : 1;
		}

		for (int i = n - 2; i >= 0; i--)
		{
			int t = dp[m - 1][i + 1] - dungeon[m - 1][i];
			dp[m - 1][i] = t > 0 ? t : 1;
		}
		for (int i = m - 2; i >= 0; i--)
		{
			for (int j = n - 2; j >= 0; j--)
			{
				int t1 = dp[i + 1][j] - dungeon[i][j];
				int t2 = dp[i][j + 1] - dungeon[i][j];
				t1 = t1>0 ? t1 : 1;
				t2 = t2>0 ? t2 : 1;
				dp[i][j] = min(t1, t2);
			}
		}
		return dp[0][0];
	}
};