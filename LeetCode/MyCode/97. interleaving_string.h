#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution97
{
public:
	//动态规划，二维dp,d[i][j]可以表达，当s1取前i个，s2取前j个，是否可以组成s3取前i+j个
	bool isInterleave(string s1, string s2, string s3)
	{
		int l1 = s1.size();
		int l2 = s2.size();
		int l3 = s3.size();
		if (l1 + l2 != l3)
			return false;
		vector<vector<bool>> dp(l1 + 1, vector<bool>(l2+1, false));
		dp[0][0] = true;
		int k = 0;
		for (int i = 1; i <= l1; i++)
		{
			if (s1[i - 1] == s3[i - 1])
			{
				dp[i][0] = true;
			}
			else
				break;
		}
		
		for (int j = 0; j <= l2; j++)
		{
			if (s2[j - 1] == s3[j - 1])
				dp[0][j] = true;
			else
				break;
		}
	
		for (int i = 1; i < l1 + 1; i++)
		{
			for (int j = 1; j < l2 + 1; j++)
			{
				dp[i][j] =dp[i][j]|| dp[i - 1][j] && s1[i-1] == s3[i + j - 1];
				dp[i][j] =dp[i][j]|| dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
			}
		}
		return dp[l1][l2];
	}
};