#include <string>
using namespace std;

class Solution65
{
public:

	//Œ‘≤€≤ª≈™¡À£¨∑≥À¿¡À°£°£°£
	bool isNumber(string s)
	{
		bool hasPoint = false;
		bool hasE = false;
		bool hasNumber = false;
		for (int i = 0; i < s.size(); i++)
		{
			int temp = i;
			if (s[i] == ' ')
			{
				while (i<s.size() && s[i] == ' ')
				{
					// s.erase(s.begin()+i);
					i++;
					//continue;
				}
				if (temp>0 && (hasNumber || hasPoint) && i<s.size())
					return false;
				//   else continue;
				if (i == s.size())
					break;
			}
			if (!isNum(s[i]))
			{
				if (s[i] == '.')
				{
					if (((i != s.size() - 1) && s[i + 1] != ' '&& !isNum(s[i + 1])) || (i != 0 && s[i - 1] != ' '&& !isNum(s[i - 1])))
						return false;
					if (hasPoint)
						return false;
					else
						hasPoint = true;
				}
				else if (s[i] == 'e')
				{
					if (i == 0 || i == s.size() - 1)
						return false;
					if (!isNum(s[i - 1]) || !isNum(s[i + 1]))
						return false;
					if (i>0 && s[i - 1] == '.')
						return false;
					if (hasE)
						return false;
					else
						hasE = true;
				}
				else return false;

			}
			else
				hasNumber = true;
		}
		return hasNumber;
	}

	bool isNum(char a)
	{
		return a >= '0'&&a <= '9';
	}

};