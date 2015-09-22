#include <string>
using namespace std;

class Solution151
{
public:
	void reverseWords(string &s)
	{
		reverse(s.begin(), s.end());
		while (s.size()>0&&s[0] == ' ')
			s = s.substr(1, s.size());
		while (s.size()>0&&s[s.size() - 1] == ' ')
			s = s.substr(0, s.size() - 1);
		for (int i = 0; i < s.size();)
		{
			int j = i;
			for (; j < s.size(); j++)
			{
				while (j + 1 < s.size() && s[j] == ' '&&s[j + 1] == ' ')
				{
					s.erase(s.begin() + j);
				}
				if (s[j] == ' ')
				{
					reverse(s.begin() + i, s.begin() + j);
					break;
				}
				if ( j == s.size() - 1)
				{
					reverse(s.begin() + i, s.begin() + j+1);
					break;
				}
				
			}
			i = j + 1;
		}
	}
};