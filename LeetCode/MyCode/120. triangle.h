#include <vector>
#include <algorithm>
using namespace std;

class Solution120
{
public:
	int minimumTotal(vector<vector<int>>& triangle)
	{
		int minimum = INT_MAX;
		if (triangle.size()==1)
			return triangle[0][0];
		for (int i = 1; i < triangle.size(); i++)
		{
			for (int j = 0; j < triangle[i].size(); j++)
			{
				int temp = 0;
				if (j>0 && j < triangle[i].size() - 2)
				{
					temp = min(triangle[i - 1][j - 1], triangle[i - 1][j]);
				}
				else if (j==triangle[i].size()-1)
				{
					temp = triangle[i - 1][j - 1];
				}
				else if (j == 0)
				{
					temp = triangle[i - 1][0];
				}
				else if (j == triangle[i].size()-2)
					temp = min(triangle[i - 1][j-1],triangle[i-1][j]);
				triangle[i][j] += temp;
			}
		}
		for (int i = 0; i < triangle.size(); i++)
		{
			minimum = min(minimum, triangle[triangle.size() - 1][i]);
		}
		return minimum;
	}
};