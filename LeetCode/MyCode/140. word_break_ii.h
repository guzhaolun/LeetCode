#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution140
{
public:
	//直接遍历，超时了。
	//然后借鉴1的动态规划先生成每个字串能否分割的状态表，不过状态表是从后往前构造。利用这个表做剪枝。
	vector<string> wordBreak(string s, unordered_set<string>& wordDict)
	{
		vector<string> res;
		string curr = "";
		vector<vector<bool>> record(s.size(),vector<bool>(s.size()+1, true));

		vector<bool> wordB(s.length() + 1, false);
		wordB[s.length()] = true;
		for (int i = 1; i < s.length() + 1; i++)
		{
			int size = s.size();
			for (int j = s.length() - 1; j >= (size - i); j--)
			{
				if (wordB[2 * s.length() - i - j] && wordDict.find(s.substr(s.length() - i, s.length() - j)) != wordDict.end()) {
					wordB[s.length() - i] = true;
					break;
				}
			}
		}
		breaks(s, wordDict, res, curr,0, s.size(),wordB,0);
		return res;
		
	}
	void breaks(string s, unordered_set<string>& wordDict, vector<string> &res, string& curr, int deep, int size, vector<bool>& record, int start)
	{
		for (int i = 1; i <= s.size(); i++)
		{
			if (wordDict.find(s.substr(0, i)) != wordDict.end())
			{
				curr += s.substr(0, i);
				if (curr.size() - deep == size)
					res.push_back(curr);
				else
					curr += " ";
				if (start+i<size&&record[start+i])
				{
					breaks(s.substr(i, s.size()-i), wordDict, res, curr, deep+1 , size, record, start+i);
				}	
				if (curr.size() - 1 >= i&&curr[curr.size()-1]==' ')
						curr = curr.substr(0, curr.size() - 1 - i);
					else
						curr = curr.substr(0, curr.size() - i);
			}
		}
	}
};
