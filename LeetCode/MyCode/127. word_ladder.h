#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

class Solution127{
public:

	//bfs����Ȼ��ʱ�ˡ�
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict)
	{
		if (beginWord == endWord)
			return 1;
		int currLen = 1;
		unordered_map<string,int> already;
		queue<string> ladder;
		already[beginWord] = 1;
		ladder.push(beginWord);
		while (!ladder.empty())
		{
			string begin = ladder.front();
			
			bool update = false;
			for (unordered_set<string>::iterator it = wordDict.begin(); it != wordDict.end(); it++)
			{
				int len = already[begin];
				if (adjacent(*it, begin) && already.find(*it) == already.end())
				{
					ladder.push(*it);
					already[*it]=len+1;
					if (*it == endWord)
					{
						return len+1;
					}
				}
			}
			ladder.pop();
		}
		return 0;
	}

	bool adjacent(string s, string t)
	{
		int count = 0;
		for (int i = 0; i < s.size();i++)
			if (s[i] != t[i])
				count++;
		return count == 1;
	}

	//�޸ģ�ֱ�Ӷ�begin�޸ģ�����26*begin.size()�Σ�����wordDictѭ����wordDict.size()�Σ��ܴ�
	int ladderLength2(string beginWord, string endWord, unordered_set<string>& wordDict)
	{
		if (beginWord == endWord)
			return 1;
		int currLen = 1;
		unordered_map<string, int> already;
		queue<string> ladder;
		already[beginWord] = 1;
		ladder.push(beginWord);
		while (!ladder.empty())
		{
			string begin = ladder.front();
			int len = already[begin];
			bool update = false;
			for (int i = 0; i < begin.size(); i++)
			{
				string begin1 = begin;
				for (char j = 'a'; j <= 'z'; j++)
				{
					
					if (begin1[i] == j)
						continue;
					begin1[i] = j;
					if (wordDict.find(begin1) != wordDict.end()&&already.find(begin1)==already.end())
					{
						ladder.push(begin1);
						already[begin1] = len + 1;
						
						if (begin1 == endWord)
							return len+1;
					}
				}
				
			}
			ladder.pop();
		}
		return 0;
	}
};