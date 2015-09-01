#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution72 
{
public:
	int minDistance(string word1, string word2)
	{
		int l1 = word1.length()+1;
		int l2 = word2.length()+1;
		vector<vector<int>> dp(l1, vector<int>(l2, 0));
		for (int i = 0; i < l1; i++)
			dp[i][0] = i;
		for (int i = 0; i < l2; i++)
			dp[0][i] = i;
		for (int i = 1; i < l1; i++)
		{
			for (int j = 1; j < l2; j++)
			{
				int t = 1;
				if (word1[i] == word2[j])
					t = 0;
				dp[i][j] =min(dp[i-1][j-1]+t, min(dp[i - 1][j], dp[i][j - 1])+1);
			
			}
		}
		return dp[l1 - 1][l2 - 1];
	}
};