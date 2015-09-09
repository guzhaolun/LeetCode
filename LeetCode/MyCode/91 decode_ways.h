#include <string>
using namespace std;

class Solution91
{
public:
	int numDecodings(string s)
	{
		if (s.empty())
			return 0;
		if (s[0] == '0')
			return 0;
		int* dp = new int[s.size()];
		memset(dp, 0, s.size()*sizeof(int));
		if (s[0] <= '9'&&s[0] > '0')
			dp[0] = 1;
		for (int i = 1; i < s.size(); i++)
		{

			if (s[i] == '0' && (s[i - 1] > '2' || s[i - 1] == '0'))
				return 0;
			if (s[i - 1] == '1' || (s[i - 1] == '2'&&s[i]<'7'))
			{
				if (i == 1)
					dp[i] += 1;
				else
					dp[i] += dp[i - 2];
			}
			if (s[i] != '0')
				dp[i] += dp[i - 1];


		}
		return dp[s.size() - 1];
	}
};