#include <vector>
using namespace std;

class Solution118
{
public:
	vector<vector<int>> generate(int numRows)
	{
		vector<vector<int>> res;
		vector<int> row;
		if (numRows == 0)
			return res;
		row.push_back(1);
		res.push_back(row);
		if (numRows == 1)
			return res;
		for (int i = 2; i <= numRows; i++)
		{
			row.clear();
			row.resize(i);
			row[0] = 1;
			row[i - 1] = 1;
			for (int j = 1; j < i-1; j++)
			{
				row[j] = res[i - 2][j - 1] + res[i - 2][j];
			}
			res.push_back(row);
		}
		return res;
	}
};