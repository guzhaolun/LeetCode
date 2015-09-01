#include <vector>
using namespace std;

class Solution73
{
public:
	void setmatrixZeros(vector<vector<int>>& matrix)
	{
		if (matrix.empty())
			return;
		int m = matrix.size();
		int n = matrix[0].size();
		bool firstrow = false;
		bool firstcolumn = false;
		for (int i = 0; i<n; i++)
		if (matrix[0][i] == 0)
			firstrow = true;
		for (int i = 0; i<m; i++)
		if (matrix[i][0] == 0)
			firstcolumn = true;

		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			if (matrix[i][j] == 0)
			{
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
		for (int i = 1; i < m; i++)
		{
			if (matrix[i][0] == 0)
				fill(&matrix[i][0], &matrix[i][0] + n, 0);
		}

		for (int i = 1; i < n; i++)
		{
			if (matrix[0][i] == 0)
			{
				for (int j = 1; j < m; j++)
					matrix[j][i] = 0;
			}
		}

		if (firstrow)
			fill(&matrix[0][0], &matrix[0][0] + n, 0);
		if (firstcolumn)
		for (int i = 0; i<m; i++)
			matrix[i][0] = 0;
	}
};