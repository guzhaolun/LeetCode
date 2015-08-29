#include <string>
using namespace std;

class Solution44
{
public:
	bool isMatch(string s, string p)
	{
		return match(s, p, 0, 0);
	}

	//递归，然后回溯，好不容易写出来了居然超时了。。。。
	bool match(string  s, string p, int i, int j)
	{
		if (s.size() == i&&p.size() == j)
			return true;
		if (j == p.size()||i==s.size())
			return false;
		if (s[i] != p[j])
		{
			if (p[j] == '?')
			{
				return match(s, p, i + 1, j + 1);
			}
			else if (p[j] == '*')
			{
				//while (j+1<p.size()&&p[j + 1] == '*')j++;
				//这两个match换换位置都会超时，只是超时的情况不同。
				if(match(s, p, i+1, j + 1))
					return true;
				return match(s, p, i+1, j);
			}
			else
				return false;
		}
		else
			return match(s, p, i + 1, j + 1);
	}

	//直接匹配好了，利用prep和pres记录未匹配的位置、
	//遇到'*'，我们只考虑遇到下一个'*'前的子问题，而不是考虑一直到末尾的子问题。从而避免大量的子问题计算。
	//以 p = "c*ab*c"，s = "cddabbac"为例
	//确实牛逼
	bool isMatch2(string s, string p)
	{
		int prep = 0, pres = 0;
		bool starFound=false;
		int j = 0;
		for (int i = 0; i < s.size();)
		{
			if (s[i] == p[j] || p[j] == '?')
			{
				i++;
				j++;
			}
			else if (p[j] == '*')
			{
				while (p[j] == '*')
					j++;
				prep = j;
				pres = i;
				starFound = true;
				continue;
			}
			else
			{
				if (starFound)
				{
					j = prep;
					i = ++pres;
				}
				else
					return false;
			}
		}
		while (p[j] == '*')
			j++;
		return j == p.size();
	}
};