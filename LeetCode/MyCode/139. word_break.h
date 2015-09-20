#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution139
{
public:
	//直接遍历，超时了。
	bool wordBreak(string s, unordered_set<string>& wordDict)
	{
		if (s.size() <= 0 || wordDict.find(s) != wordDict.end())
			return true;
		if (s.size() == 1)
			return wordDict.find(s) != wordDict.end();
		for (int i = 1; i < s.size(); i++)
		{
			if (wordBreak(s.substr(0, i), wordDict) && wordBreak(s.substr(i, s.size()), wordDict))
				return true;
		}
		return false;
	}

	//动态规划，F(0,N)=F(0，i)&&F(i,N)
	bool wordBreak2(string s, unordered_set<string>& dict)
	{
		//从前向后
		//vector<bool> wordB(s.length() + 1, false);
		//wordB[0] = true;
		//for (int i = 1; i < s.length() + 1; i++) {
		//	for (int j = 0; j < i; j++) {
		//		if (wordB[j] && dict.find(s.substr(j, i-j)) != dict.end()) {
		//			wordB[i] = true;
		//			break; //只要找到一种切分方式就说明长度为i的单词可以成功切分，因此可以跳出内层循环。  
		//		}
		//	}
		//}
		//return wordB[s.length()];

		//从后向前
		vector<bool> wordB(s.length() + 1, false);
		wordB[s.length()] = true;
		for (int i = 1; i < s.length() + 1; i++)
		{
			int size = s.size();//为什么直接写成（s.size()-i)就不判断了啊，，妹的
			for (int j = s.length() - 1; j>=(size - i); j--)
			{
				if (wordB[2*s.length()-i-j] && dict.find(s.substr(s.length() - i, s.length() - j)) != dict.end()) {
					wordB[s.length() - i] = true;
					break;
				}
			}
		}
		return wordB[0];
	}
};