#include <string>
#include <algorithm>
using namespace std;

class Solution214
{
public:

	//从中间往两边找，超时了。。
	string shortestPalindrome(string s)
	{
		int size = s.size();
		int mid = size / 2 - 1;
		int i = mid;
		int left, right;
		for (; i >= 0; i--)
		{
			left = i - 1, right = i + 1;
			while (left >= 0 && right < size&&s[left] == s[right])
			{
				left--;
				right++;
			}
			if (left < 0)
				break;

		}
		int curr = size - right;
		int currRight = right;
		i = mid;
		for (; i >= 0; i--)
		{
			left = i, right = i + 1;
			while (left >= 0 && right < size&&s[left] == s[right])
			{
				left--;
				right++;
			}
			if (left < 0)
				break;
		}
		currRight = max(currRight, right);
		string res = s;
		for (int i = currRight; i < size; i++)
		{
			res.insert(res.begin(), s[i]);
		}
		return res;
	}

	//利用kmp算法求next数组的过程，找出拼接后的最长公共前缀后缀。
	string shortestPalindrome2(string s)
	{
		string rs = s;
		string temp = s;
		reverse(rs.begin(), rs.end());
		s = s + '#' + rs;
		vector<int> next(s.size() + 1, 0);
		getNext(s, next);
		return rs.substr(0, rs.length() - next[s.size()]) + temp;
	}

	void getNext(string s, vector<int>& next)
	{
		int j = -1, i = 0;
		next[0] = -1;
		while (i < s.size())
		{
			if (j == -1 || s[i] == s[j])
			{
				i++;
				j++;
				next[i] = j;
			}
			else
				j = next[j];
		}
	}

	//利用manacher算法找最长回文子串的，也是线性时间。
	///http://www.cnblogs.com/easonliu/p/4522724.html
	int longestPalindrom(string s) {
		string s1;
		s1.resize(2 * s.length() + 2);
		int idx = 0;
		s1[idx++] = '$';
		s1[idx++] = '#';
		for (char a : s) {
			s1[idx++] = a;
			s1[idx++] = '#';
		}
		vector<int> p(s1.length(), 0);
		int res = 0;
		for (int id = 0, i = 1; i < s1.length(); ++i) {
			if (i < id + p[id]) p[i] = min(p[2 * id - i], id + p[id] - i);
			else p[i] = 1;
			while (s1[i + p[i]] == s1[i - p[i]]) ++p[i];
			if (id + p[id] < i + p[i]) id = i;
			if (p[i] == i) res = max(res, i);
		}
		return res - 1;
	}

	string shortestPalindrome3(string s) {
		int pos = longestPalindrom(s);
		string res;
		for (int i = s.length() - 1; i >= pos; --i) res.push_back(s[i]);
		return res + s;
	}

};