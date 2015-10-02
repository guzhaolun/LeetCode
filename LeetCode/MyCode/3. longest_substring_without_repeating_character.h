#include <string>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s)
	{
		long visit[256];
		memset(visit, -1, sizeof visit);
		string result;
		int last_start = 0;
		//int i = 1, end = 0, start = 0;;
		visit[s[0]] = 0;
		int current = 1;
		int maxlen = 0, maxindex = 0;
		if (s.length() == 1)
			return 1;
		for (int i = 1; i < s.length(); i++)
		{
			if (visit[s[i]] == -1)
			{
				current++;
				visit[s[i]] = i;
			}
			else if (last_start <= visit[s[i]])
			{
				current = i - visit[s[i]];
				last_start = visit[s[i]] + 1;
				visit[s[i]] = i;
			}
			else{
				current++;
				visit[s[i]] = i;
			}

			if (current > maxlen)
			{
				maxlen = current;
				maxindex = i - maxlen + 1;
			}
		}
		return maxlen;
	}
};