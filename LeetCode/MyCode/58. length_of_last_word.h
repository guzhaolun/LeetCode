#include <string>
using namespace std;

class Solution58
{
public:
	int lengthOfLastWord(string s)
	{
		int begin = 0;
		for (int i = s.size() - 1; i >= 0; i--)
		{
			if (s[i] == ' ')
				continue;
			else
			{
				begin = i;
				while (i>=0&&s[--i] != ' ');
				return begin - i;
			}
		}
		return 0;
	}
};