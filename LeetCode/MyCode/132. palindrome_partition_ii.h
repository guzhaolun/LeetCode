#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution132
{
public:
	int minCut(string s)
	{
		vector<vector<string>> res;
		vector<string> curr;
		int len = 0, totalLen = s.size(), cut = 0;
		part(s, res, curr, len, totalLen, cut);
		if (res.empty())
			return 0;
		int m = res[0].size();
		res.clear();
		reverse(s.begin(), s.end());
		part(s, res, curr, len, totalLen, cut);
		int n = res[0].size();
		return m < n ? m - 1 : n - 1;
	}
	//还是这种方法做，超时了，递归还是太慢。
	void part(string s, vector<vector<string>>& res, vector<string> curr, int len, int totalLen, int& cut)
	{
		if (s.size() <= 0)
			return;
		for (int i = s.size() - 1; i >= 0; i--)
		{
			if (s[0] == s[i])
			{
				if (palindrome(s.substr(0, i + 1)))
				{
					curr.push_back(s.substr(0, i + 1));
					len += i + 1;
					cut++;
				}
				if (len == totalLen)
				{
					res.push_back(curr);
					return;
				}
				part(s.substr(i + 1, s.size()), res, curr, len, totalLen, cut);
				if (!curr.empty())
				{
					len -= curr[curr.size() - 1].size();
					curr.pop_back();
					cut--;
				}
			}
		}
	}

	bool palindrome(string s)
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != s[s.size() - 1 - i])
				return false;
		}
		return true;
	}

	//动态规划，
	//dp[right] = min(dp[right], dp[left - 1] + 1); 更新过的
	//dp[right] = dp[left - 1] + 1;; 没更新过的
	//从不懂动态规划到现在能自己做出这种题，有进步啊，哈哈
	int minCut2(string s)
	{
		vector<int> dp(s.size(), 0);
		vector<bool> update(s.size(), false);
		for (int i = 0; i < s.size(); i++)
		{
			int left = i, right = i;
			
			while (left > 0 && right < s.size() - 1 && s[--left] == s[++right])
			{
				if (left == 0)
					dp[right] = 0;
				else if (update[right])
					dp[right] = min(dp[right], dp[left - 1] + 1);
				else
					dp[right] = dp[left - 1] + 1;
				update[right] = true;
			}
			left = i; right = i - 1;
			while (left > 0 && right < s.size() - 1 && s[--left] == s[++right])
			{
				if (left == 0)
					dp[right] = 0;
				else if (update[right])
					dp[right] = min(dp[right], dp[left - 1] + 1);
				else
					dp[right] = dp[left - 1] + 1;
				update[right] = true;
			}
			if (i>0)
			{
				if (!update[i])
					dp[i] = dp[i - 1] + 1;
				else
					dp[i] = min(dp[i], dp[i - 1] + 1);
			}
		}
		return dp[s.size() - 1];
	}
};