#include <string>
using namespace std;

class Solution115
{
public:
	//µ›πÈ£¨…ÓÀ—
	int numDistinct(string s, string t)
	{
		int count = 0;
		dfs(s, 0, t, 0, count);
		return count;
	}

	void dfs(string s, int i, string t, int j, int& count)
	{
		if (i == s.size())
		{
			if (j == t.size())
				count++;
			return;
		}
		else if (s[i] == t[j])
			dfs(s, i + 1, t, j + 1, count);

		dfs(s, i + 1, t, j, count);
	}

	int numDistinct(string s, string t)
	{
		int l1 = s.size();
		int l2 = t.size();
		vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
		dp[0][0] = 1;
		for (int i = 0; i < l1 + 1; i++)
			dp[i][0] = 1;
		for (int i = 1; i <= l1; i++)
		{
			for (int j = 1; j <= l2; j++)
			{
				dp[i][j] = dp[i - 1][j];
				if (s[i - 1] == t[j - 1])
					dp[i][j] += dp[i - 1][j - 1];
			}
		}
		return dp[l1][l2];
	}
};