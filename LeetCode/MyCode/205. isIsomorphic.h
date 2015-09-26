#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution205
{
public:
	bool isIsomorphic(string s, string t) 
	{
		if (s.size() != t.size())
			return false;
		unordered_map<char, char> already;
		unordered_set<char> alpha;
		for (int i = 0; i < s.size(); i++)
		{
			if (already.find(s[i]) == already.end()&&alpha.find(t[i])==alpha.end())
			{
				already[s[i]] = t[i];
				alpha.insert(t[i]);
			}
			else if (already[s[i]] != t[i])
				return false;
		}
		return true;
	}
};