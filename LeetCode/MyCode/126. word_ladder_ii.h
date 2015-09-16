#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

class Solution126
{
public:
	//广搜，记录前缀，然后深搜
	//刚开始无法判断终止条件，然后加上length后可以了，但是还是删除多了
	//因为路径有重复的也给误删了，比如两个合并到一条路的，然后就我尼玛了，日
	//
	//
	//然后我服，搜了一份代码，是用两个vector来模拟队列，我们从vector 1中遍历单词进行转换尝试，
	//发现能转换的单词后将其放入vector 2中。当vector 1中的单词处理完毕后即为一层处理完毕，
	//它里面的单词就可以从字典里删去了。接着我们对vector 2进行同样处理，如此反复直到当前处理的vector中不再有单词。
	//这样只会保证上层出现过的这层不会出现，而不会将这层前面出现过的也踢除。
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