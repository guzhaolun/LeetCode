#include <vector>
using namespace std;

class Solution93
{
public:
	vector<string> restoreIpAddresses(string s)
	{
		string curr;
		vector<string> res;
		compute(s, 0, 0, curr, res);
		return res;
	}

	void compute(string s, int deep, int index, string curr, vector<string> &res)
	{
		if (curr.size() - 3 == s.size() && deep == 4)
		{
			res.push_back(curr);
			return;
		}
		if (deep > 4 || index >= s.size())
			return;

		for (int j = 3; j > 0; j--)
		{
			if (s.size() - index<j)
				continue;
			string temp = s.substr(index, j);
			if (atoi(temp.c_str())>255||temp[0]=='0'&&temp.size()>1)
				continue;
			curr.append(s.substr(index, j));
			if (deep != 3)
				curr.append(".");
			compute(s, deep + 1, index + j, curr, res);
			curr = curr.substr(0, index + deep);
		}

	}
};