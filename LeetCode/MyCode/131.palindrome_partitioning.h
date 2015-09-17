#include <vector>
#include <string>
using namespace std;

class Solution131
{
public:
	vector<vector<string>> partition(string s)
	{
		vector<vector<string>> res;
		vector<string> curr;
		int len = 0,totalLen=s.size();
		part(s, res, curr,len,totalLen);
		return res;
	}
	
	void part(string s, vector<vector<string>>& res, vector<string> curr, int len, int totalLen)
	{
		if (s.size() <= 0)
			return;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[0] == s[i])
			{
				if (palindrome(s.substr(0, i + 1)))
				{
					curr.push_back(s.substr(0, i + 1));
					len += i + 1;
				}
				else//不加这个超时了，没有及时中断
					continue;
				if (len == totalLen)
				{
					res.push_back(curr);
					continue;
				}
				part(s.substr(i + 1, s.size()), res, curr,len,totalLen);
				if (!curr.empty())
				{
					len -= curr[curr.size() - 1].size();
					curr.pop_back();
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
};