#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

class Solution126
{
public:
	//���ѣ���¼ǰ׺��Ȼ������
	//�տ�ʼ�޷��ж���ֹ������Ȼ�����length������ˣ����ǻ���ɾ������
	//��Ϊ·�����ظ���Ҳ����ɾ�ˣ����������ϲ���һ��·�ģ�Ȼ����������ˣ���
	//
	//
	//Ȼ���ҷ�������һ�ݴ��룬��������vector��ģ����У����Ǵ�vector 1�б������ʽ���ת�����ԣ�
	//������ת���ĵ��ʺ������vector 2�С���vector 1�еĵ��ʴ�����Ϻ�Ϊһ�㴦����ϣ�
	//������ĵ��ʾͿ��Դ��ֵ���ɾȥ�ˡ��������Ƕ�vector 2����ͬ��������˷���ֱ����ǰ�����vector�в����е��ʡ�
	//����ֻ�ᱣ֤�ϲ���ֹ�����㲻����֣������Ὣ���ǰ����ֹ���Ҳ�߳���
	vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string>& wordDict)
	{
		vector< vector<string>> res;
		vector<string> temp;
		temp.push_back(beginWord);
		if (beginWord == endWord)
		{
			res.push_back(temp);
			return res;
		}
		int currLen = 1;
		int minLen = INT_MAX;
		unordered_map<string, vector<string>> back;
		unordered_set<string> already;
		queue<string> ladder;
		already.insert(beginWord);
		ladder.push(beginWord);
		int size = 0;
		int minsize = 0;
		bool update = false;
		unordered_map<string, int> len;
		len[beginWord] = 1;
		while (!ladder.empty()&&size==minsize)
		{
			string begin = ladder.front();
			int lens = len[begin];
			for (int i = 0; i < begin.size(); i++)
			{
				string begin1 = begin;
				for (char j = 'a'; j <= 'z'; j++)
				{
					if (begin1[i] == j)
						continue;
					begin1[i] = j;
					if (begin1 == endWord)
					{
						
						size = lens + 1;
						len[begin1] = size;
						if (!update)
						{
							update = true;
							minsize = lens+1;
						}
						if (size > minsize)
							break;
						back[begin1].push_back(begin);
					}
					else if (wordDict.find(begin1) != wordDict.end() && already.find(begin1) == already.end())
					{
						ladder.push(begin1);
						already.insert(begin1);
						len[begin1] = lens + 1;
						back[begin1].push_back(begin);
					}
				}
			}
			ladder.pop();
		}
		vector<string> curr;
		curr.push_back(endWord);
		generatePath(curr, res, back, endWord);
		for (int i = 0; i < res.size(); i++)
			reverse(res[i].begin(), res[i].end());
		return res;
	}

	void generatePath(vector<string> curr, vector<vector<string>>& path, unordered_map<string, vector<string>>& back, string end)
	{
		vector<string> temp;
		if (back.count(end)>0)
			temp = back[end];
		else
			path.push_back(curr);
		for (int i = 0; i < temp.size(); i++)
		{
			curr.push_back(temp[i]);
			generatePath(curr, path, back, temp[i]);
			curr.pop_back();
		}
	}
};

class Solution {
public:
	vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict)
	{
		result_.clear();
		unordered_map<string, vector<string>> prevMap;
		for (auto iter = dict.begin(); iter != dict.end(); ++iter)
			prevMap[*iter] = vector<string>();
		vector<unordered_set<string>> candidates(2);
		int current = 0;
		int previous = 1;
		candidates[current].insert(start);
		while (true)
		{
			current = !current;
			previous = !previous;
			for (auto iter = candidates[previous].begin(); iter != candidates[previous].end(); ++iter)
				dict.erase(*iter);
			candidates[current].clear();

			for (auto iter = candidates[previous].begin(); iter != candidates[previous].end(); ++iter)
			{
				for (size_t pos = 0; pos < iter->size(); ++pos)
				{
					string word = *iter;
					for (int i = 'a'; i <= 'z'; ++i)
					{
						if (word[pos] == i)continue;
						word[pos] = i;
						if (dict.count(word) > 0)
						{
							prevMap[word].push_back(*iter);
							candidates[current].insert(word);
						}
					}
				}
			}
			if (candidates[current].size() == 0)
				return result_;
			if (candidates[current].count(end)) break;
		}
		vector<string> path;
		GeneratePath(prevMap, path, end);
		return result_;
	}

private:
	void GeneratePath(unordered_map<string, vector<string>> &prevMap, vector<string>& path, const string& word)
	{
		if (prevMap[word].size() == 0)
		{
			path.push_back(word);
			vector<string> curPath = path;
			reverse(curPath.begin(), curPath.end());
			result_.push_back(curPath);
			path.pop_back();
			return;
		}
		path.push_back(word);
		for (auto iter = prevMap[word].begin(); iter != prevMap[word].end(); ++iter)
			GeneratePath(prevMap, path, *iter);
		path.pop_back();
	}
	vector<vector<string>> result_;
};