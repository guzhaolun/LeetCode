#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
	
};

class Solution 
{
public:
	//本来以为要三层循环呢，吓尿了，后来发现不是，对每一个点分别与其他点求斜率就好。
	int maxPoints(vector<Point>& points)
	{
		if (points.empty())
			return 0;
		unordered_map<float, int> ks;
		int maxCount = 0;
		for (int i = 0; i < points.size(); i++)
		{
			ks.clear();
			int currMax = 0;
			int same = 0;
			for (int j = 0; j < points.size(); j++)
			{
				if (i == j || (points[i].x == points[j].x&&points[i].y == points[j].y))
				{
					same++;
					continue;
				}
				if (points[i].x == points[j].x)
				{
					ks[INT_MAX]++;
					currMax = max(currMax, ks[INT_MAX]);
				}
				else
				{
					float k = float(points[i].y - points[j].y) / (points[i].x - points[j].x);
					ks[k]++;
					currMax = max(currMax, ks[k]);
				}

			}
			maxCount = max(maxCount, currMax + same);
		}
		return maxCount;
	}
};