#include <vector>
#include <algorithm>
using namespace std;

class Solution64
{
public:
	int minPathSum(vector<vector<int>>& grid)
	{
		if (grid.empty())
			return 0;
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<int>> res(m,vector<int>(n,0));
		res[0][0] = grid[0][0];
		for (int i = 1; i < m; i++)
			res[i][0] = res[i-1][0]+grid[i][0];
		for (int i = 1; i < n; i++)
			res[0][i] = res[0][i-1]+grid[0][i];
		
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				res[i][j] = grid[i][j] + min(res[i - 1][j], res[i][j - 1]);
			}
		}
		return res[m-1][n-1];
	}

	//用递归，果然超时了。。。
	void findMin(vector<vector<int>>& grid, int& minsum, int currsum, int i, int j)
	{
		if (i < 0 || j < 0)
			return;
		currsum += grid[i][j];
		if (i == 0 && j == 0)
			minsum = min(currsum, minsum);
		else
		{
			findMin(grid, minsum, currsum, i - 1, j );
			findMin(grid, minsum, currsum, i, j-1);
		}
	}
};