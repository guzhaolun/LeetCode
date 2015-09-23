#include <string>
#include <vector>

using namespace std;

class Solution165
{
public:
	int compareVersion(string version1, string version2)
	{
		vector<vector<int>> v;
		v.resize(2);
		for (int i = 0; i < 2; i++)
		{
			string s;
			if (i == 0)
				s = version1;
			else
				s = version2;
			while (1)
			{
				int dot = s.find_first_of('.');
				string s1 = s.substr(0, dot);
				int a = atoi(s1.c_str());
				v[i].push_back(a);
				if (dot >= 0)
					s = s.substr(dot + 1);
				else
					break;
			}
		}
		for (int i = 0; i < 2; i++)
		{
			while (v[i][v[i].size() - 1] == 0)
				v[i].pop_back();
		}
		int size = min(v[0].size(), v[1].size());
		for (int i = 0; i < size; i++)
		{
			if (v[0][i]>v[1][i])
				return 1;
			else if (v[0][i] < v[1][i])
				return -1;
			else if(i==size-1)
			{
				if (v[0].size() == v[1].size())
					return 0;
				else if (v[0].size()>v[1].size())
					return 1;
				else return -1;
			}
		}
	}
};