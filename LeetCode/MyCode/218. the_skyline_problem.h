#include<vector>
#include <algorithm>
using namespace std;

enum Type{ LEFT, RIGHT };
class Node
{
public:
	int x;
	int height;
	Type type;
	Node(int x, int y, Type n) :x(x), height(y), type(n){}
};
class Solution218
{
public:
	//改了半天还是有些case没过。。疯了啊。。。果然hard不是随便就能过的。。
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings)
	{
		vector<Node> node;
		for (int i = 0; i < buildings.size(); i++)
		{
			node.push_back(Node(buildings[i][0], buildings[i][2], LEFT));
			node.push_back(Node(buildings[i][1], buildings[i][2], RIGHT));
		}
		sort(node.begin(), node.end(), cmp);
		int maxH = 0;
		int maxH_x = -1;
		vector<pair<int, int>> res;
		if (node.empty())
			return res;
		for (int i = 0; i < node.size(); i++)
		{
			int h = node[i].height;
			while (i + 1 < node.size() && node[i].x == node[i + 1].x&&node[i + 1].type == LEFT)
			{
				h = max(h, node[i + 1].height);
				i++;
			}
			if (h > maxH)
			{
				res.push_back(make_pair(node[i].x, h));
			}
			else if (node[i].type == RIGHT)
			{
				if (node[i].height <= maxH)
				{
					while (node[i].height > res[res.size() - 1].second&&!res.empty())
						res.pop_back();
					int x = maxH_x;
					for (int k = i - 1; k >= 0; k--)
					{
						if (node[k].height > node[i].height)
						{
							x = max(maxH_x, node[k].x);
							break;
						}
					}

					if (res[res.size() - 1].second != h)
						res.push_back(make_pair(x, h));
				}
			}
			if (i + 1 < node.size() && node[i].type == RIGHT&&!res.empty() && node[i + 1].type == LEFT&&node[i].x != node[i + 1].x)
			{
				res.push_back(make_pair(node[i].x, 0));
				maxH = 0;
				maxH_x = node[i].x;
			}
			if (h >= maxH)
			{
				maxH = h;
				maxH_x = node[i].x;
			}
		}
		res.push_back(make_pair(node[node.size() - 1].x, 0));
		return res;
	}

	static bool cmp(Node& n1, Node& n2)
	{
		if (n1.x != n2.x)
			return n1.x < n2.x;
		else if (n1.type == LEFT&&  n2.type == LEFT)
			return n1.height >n2.height;
		else if (n1.type == RIGHT&&  n2.type == RIGHT)
			return n1.height > n2.height;
		else
			return n1.type > n2.type;
	}

	//巧用数据结构，巧用正负值，好牛逼的代码！！
	vector<pair<int, int>> getSkyline2(vector<vector<int>>& buildings)
	{
		vector<pair<int, int>> height;
		for (auto &b : buildings) {
			height.push_back({ b[0], -b[2] });
			height.push_back({ b[1], b[2] });

		}
		sort(height.begin(), height.end());
		multiset<int> heap;
		heap.insert(0);
		vector<pair<int, int>> res;
		int pre = 0, cur = 0;
		for (auto &h : height) {
			if (h.second < 0) {
				heap.insert(-h.second);

			}
			else {
				heap.erase(heap.find(h.second));

			}
			cur = *heap.rbegin();
			if (cur != pre) {
				res.push_back({ h.first, cur });
				pre = cur;

			}

		}
		return res;
	}

	//还有一种很巧妙的，直接离散化每条线，高度变化的时候就输出，太简洁了。不过building的右边届非常大时无法申请数组。。
	vector<pair<int, int>> getSkyline3(vector<vector<int>>& buildings)
	{
		vector<int> height(INT_MAX, 0);
		int maxr = 0;
		vector<pair<int, int>> res;
		if (buildings.empty())
			return res;
		for (int i = 0; i < buildings.size(); i++)
		{
			for (int j=buildings[i][0]; j < buildings[i][1]; j++)
				height[j] = max(height[j], buildings[i][2]);
			maxr = max(maxr, buildings[i][1]);
		}
		if (height[0]!=0)
			res.push_back(make_pair(0, height[0]));
		for (int i = 1; i < maxr; i++)
		{
			if (height[i] != height[i - 1])
				res.push_back(make_pair(i, height[i]));
		}
		res.push_back(make_pair(maxr, 0));
		return res;
	}
};