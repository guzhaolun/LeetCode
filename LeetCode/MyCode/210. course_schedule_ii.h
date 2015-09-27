#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
	{
		unordered_multimap<int, int> post;
		unordered_map<int, int> degrees;
		unordered_set<int> c;
		queue<int> zeros;
		vector<int> res;
		for (int i = 0; i < prerequisites.size(); i++)
		{
			post.insert(make_pair(prerequisites[i].second, prerequisites[i].first));
			if (degrees.find(prerequisites[i].second) == degrees.end())
				degrees[prerequisites[i].second] = 0;
			degrees[prerequisites[i].first]++;
		}


		for (unordered_map<int, int>::iterator it = degrees.begin(); it != degrees.end(); it++)
		{
			if (it->second == 0)
			{
				zeros.push(it->first);
			}
		}
		while (!zeros.empty())
		{
			int curr = zeros.front();
			res.push_back(curr);
			c.insert(curr);
			unordered_multimap<int, int>::iterator m = post.find(curr);
			int size = post.count(curr);
			for (int i = 0; i < size; i++)
			{

				if (--degrees[m->second] == 0)
				{
					zeros.push(m->second);
				}
				m = post.erase(m);//注意这个删除后m为空，返回下一个。

			}
			zeros.pop();
		}
	
		for (int i = 0; i < numCourses; i++)
		{
			if (c.find(i) == c.end())
				res.push_back(i);
		}
		if (!post.empty())
		{
			res.clear();
		}
		return res;
	}
};