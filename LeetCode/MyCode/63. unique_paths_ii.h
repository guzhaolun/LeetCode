#include <vector>
using namespace std;

class Solution63
{
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
	{
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<vector<int>> res(m, vector<int>(n, 0));
		for (int i = 0; i < n; i++)
		{
			if (obstacleGrid[0][i] != 1)
				res[0][i] = 1;
			else
				break;
		}
		for (int i = 0; i < n; i++)
		{
			if (obstacleGrid[i][0] != 1)
				res[i][0] = 1;
			else
				break;
		}
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				if (obstacleGrid[i][j] == 1)
					res[i][j] = 0;
				if (obstacleGrid[i - 1][j] != 1 && obstacleGrid[i][j - 1] != 1)
					res[i][j] = res[i - 1][j] + res[i][j - 1];
				else if (obstacleGrid[i - 1][j] != 1)
					res[i][j] = res[i - 1][j];
				else if (obstacleGrid[i][j - 1] != 1)
					res[i][j] = res[i][j - 1];
				else
					res[i][j] = 0;
			}
		}
		return res[m - 1][n - 1];
	}
};