#include <vector>
using namespace std;

class Solution53
{
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix)
	{
		int i = 0, j = -1;
		vector<int> res;
		if (matrix.empty())
			return res;
		vector<vector<int>> a(matrix.size(), vector<int>(matrix[0].size(), 0));

		while (res.size()!=matrix.size()*matrix[0].size())
		{

			while (j + 1 < matrix[0].size() && !a[i][j + 1])
			{
				j++;
				res.push_back(matrix[i][j]);
				a[i][j] = 1;
			}

			while (i + 1 < matrix.size() && !a[i + 1][j])
			{
				i++;
				res.push_back(matrix[i][j]);
				a[i][j] = 1;
			}

			while (j >= 1 && !a[i][j - 1])
			{
				j--;
				res.push_back(matrix[i][j]);
				a[i][j] = 1;
			}

			while (i >= 1 && !a[i - 1][j])
			{
				i--;
				res.push_back(matrix[i][j]);
				a[i][j] = 1;
			}

		}
		return res;
	}
};