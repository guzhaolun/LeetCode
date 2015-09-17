#include <vector>
#include <queue>
#include <unordered_set>
#include <map>

using namespace std;
//Definition for undirected graph.
 struct UndirectedGraphNode
 {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
	
};

class Solution 
{
public:
	//其实可以考虑利用map<UndirectedGraphNode*, UndirectedGraphNode*> 直接找原来的节点，newRest和NewAlready都可以不用了，少占用几个空间
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
	{
		if (!node)
			return NULL;
		UndirectedGraphNode* res = new UndirectedGraphNode(node->label);
		queue<UndirectedGraphNode*> rest;
		queue<UndirectedGraphNode*> newRest;
		map<int,UndirectedGraphNode*> already;
		map<int,UndirectedGraphNode*> newAlready;
		rest.push(node);
		already[node->label]=node;
		newAlready[res->label]=res;
		newRest.push(res);
		while (!rest.empty())
		{
			vector<UndirectedGraphNode*> nei;
			vector<UndirectedGraphNode*> temp = rest.front()->neighbors;
			UndirectedGraphNode* newTemp = newRest.front();
			for (int i = 0; i < temp.size(); i++)
			{
				UndirectedGraphNode* n;
				if (already.find(temp[i]->label) == already.end())
				{
					already[temp[i]->label]=temp[i];
					rest.push(temp[i]);

					n = new UndirectedGraphNode(temp[i]->label);
					newRest.push(n);
				}
				else
					n = newAlready[temp[i]->label];
				newAlready[n->label] = n;
				nei.push_back(n);
			}
			newTemp->label = rest.front()->label;
			newTemp->neighbors = nei;
			rest.pop();
			newRest.pop();
		}
		return res;
	}
};