#include <string>
#include<vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution49
{
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs)
	{
		vector<vector<string>> res;
		vector<string> temp = strs;
		map<string, int> dic;
		map<string, int>::iterator it;
		int index = 0;
		for (int i = 0; i < strs.size(); i++)
		{
			sort(strs[i].begin(), strs[i].end());
			if ((it=dic.find(strs[i]))==dic.end())
			{
				dic.insert(make_pair(strs[i], index++));
				vector<string> newstr;
				newstr.push_back(strs[i]);
				res.push_back(newstr);
			}
			else
			{
				res[it->second].push_back(temp[i]);
			}
		}
		for (int i = 0; i < res.size(); i++)
		{
			sort(res[i].begin(), res[i].end());
		}
		return res;
	}
};