#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution139
{
public:
	//ֱ�ӱ�������ʱ�ˡ�
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

	//��̬�滮��F(0,N)=F(0��i)&&F(i,N)
	bool wordBreak2(string s, unordered_set<string>& dict)
	{
		//��ǰ���
		//vector<bool> wordB(s.length() + 1, false);
		//wordB[0] = true;
		//for (int i = 1; i < s.length() + 1; i++) {
		//	for (int j = 0; j < i; j++) {
		//		if (wordB[j] && dict.find(s.substr(j, i-j)) != dict.end()) {
		//			wordB[i] = true;
		//			break; //ֻҪ�ҵ�һ���зַ�ʽ��˵������Ϊi�ĵ��ʿ��Գɹ��з֣���˿��������ڲ�ѭ����  
		//		}
		//	}
		//}
		//return wordB[s.length()];

		//�Ӻ���ǰ
		vector<bool> wordB(s.length() + 1, false);
		wordB[s.length()] = true;
		for (int i = 1; i < s.length() + 1; i++)
		{
			int size = s.size();//Ϊʲôֱ��д�ɣ�s.size()-i)�Ͳ��ж��˰������õ�
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