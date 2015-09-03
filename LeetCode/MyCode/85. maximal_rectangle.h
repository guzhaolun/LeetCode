#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int maximalRectangle(vector<vector<char>>& matrix)
	{
		int maxA = INT_MIN;
		if (matrix.empty())
			return 0;
		vector<vector<int>> height;
		height.resize(matrix[0].size());
		for (int j = 0; j < matrix[0].size(); j++)
		{
			height[0][j] = matrix[0][j] - '0';
		}
		for (int i = 1; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[0].size(); j++)
			{
				height[i][j] = height[i - 1][j] + matrix[i][j] - '0';
			}
			maxA = max(maxA, largestRectangleArea(height[i]));
		}
		return maxA;
	}

	int largestRectangleArea(vector<int> height)
	{
		if (height.empty())
			return 0;
		height.push_back(0);
		stack<int> hs;
		int maxA = INT_MIN;
		for (int i = 0; i < height.size(); i++)
		{
			if (hs.empty() || height[i]>height[hs.top()])
				hs.push(i);
			else
			{
				int temp = hs.top();
				hs.pop();
				int area = height[temp] * (hs.empty() ? i : i - hs.top() - 1);
				maxA = max(maxA, area);
				i--;
			}
		}
		return maxA;
	}
};