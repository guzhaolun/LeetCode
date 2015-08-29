#include <string>
using namespace std;

class Solution44
{
public:
	bool isMatch(string s, string p)
	{
		return match(s, p, 0, 0);
	}

	//�ݹ飬Ȼ����ݣ��ò�����д�����˾�Ȼ��ʱ�ˡ�������
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
				//������match����λ�ö��ᳬʱ��ֻ�ǳ�ʱ�������ͬ��
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

	//ֱ��ƥ����ˣ�����prep��pres��¼δƥ���λ�á�
	//����'*'������ֻ����������һ��'*'ǰ�������⣬�����ǿ���һֱ��ĩβ�������⡣�Ӷ������������������㡣
	//�� p = "c*ab*c"��s = "cddabbac"Ϊ��
	//ȷʵţ��
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