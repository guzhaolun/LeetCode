#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution207
{
public:
	//��������ÿ��ȡ����ȵļ�����У��������Ƿ���ʣ��ıߡ�
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) 
	{
		unordered_multimap<int, int> post;
		unordered_map<int, int> degrees;
		queue<int> zeros;
		for (int i = 0; i < prerequisites.size(); i++)
		{
			post.insert(make_pair(prerequisites[i].first, prerequisites[i].second));
			if (degrees.find(prerequisites[i].first) == degrees.end())
				degrees[prerequisites[i].first] = 0;
			degrees[prerequisites[i].second]++;
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
			unordered_multimap<int, int>::iterator m = post.find(curr);
			int size = post.count(curr);
			for (int i = 0; i < size; i++)
			{

				if (--degrees[m->second] == 0)
				{
					zeros.push(m->second);
				}	
				m = post.erase(m);//ע�����ɾ����mΪ�գ�������һ����
				
			}
			zeros.pop();
		}
		return post.empty();
	}
};