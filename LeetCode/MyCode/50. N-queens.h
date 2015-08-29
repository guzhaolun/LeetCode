#include <vector>
#include <string>
using namespace std;

class Solution50
{
public:
	vector<vector<string>> solveNQueens(int n)
	{
		row = new int[n];
		vector<vector<string>> res;
		vector<string> curr;
		curr.resize(n);
		for (int i = 0; i < n;i++)
		for (int j = 0; j < n; j++)
			curr[i] += '.';
		solve(res, n, 0, curr,0);
		return res;
	}

	void solve(vector<vector<string>>& res, int n, int i,vector<string> curr,int q)
	{
		if (q == n)
		{
			res.push_back(curr);
			return;
		}
		//int j = index%n;
		for (int k = 0; k < n; k++)
		{
			if (checkDiag(i,k))
			{
				row[i] = k;
				curr[i][k] = 'Q';
				solve(res, n, i + 1, curr,q+1);
				row[i] = -10000;
				curr[i][k] = '.';
			}
		}
		//}
	}
	bool checkDiag(int rows,int k)
	{
		for (int i = 0; i < rows; i++)
		{
			if (row[i] == k || abs(row[i] - k) == rows - i)
				return false;
		}
		return true;
	}
private:
	int *row;
};