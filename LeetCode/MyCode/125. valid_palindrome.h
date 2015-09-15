#include <string>
using namespace std;

class Solution125
{
public:
	bool isPalindrome(string s)
	{
		if (s.empty())
			return true;
		int i = 0, j = s.size() - 1;
		while (i <= j)
		{
			char a = transform(s[i]);
			char b = transform(s[j]);
			if ((a > 'z' || a < 'a') && (a<'0' || a>'9'))
			{
				i++;
				continue;
			}
			if ((b>'z' || b < 'a') && (b<'0' || b>'9'))
			{
				j--;
				continue;
			}
			else
			{
				if (a != b)
					return false;
				else { i++; j--; }
			}
		}
		return true;
	}

	char transform(char s)
	{
		if (s >= 'A'&&s <= 'Z')
			return s - ('A' - 'a');
		else
			return s;
	}
};