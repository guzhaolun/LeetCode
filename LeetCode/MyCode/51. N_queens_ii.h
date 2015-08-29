#include <vector>
#include <string>
using namespace std;

class Solution51
{
public:
	int totalNQueens(int n)
	{
		row = new int[n];
		int res=0;
		solve(res, n, 0, 0);
		return res;
	}

	void solve(int& res, int n, int i, int q)
	{
		if (q == n)
		{
			res++;
			return;
		}
		//int j = index%n;
		for (int k = 0; k < n; k++)
		{
			if (checkDiag(i, k))
			{
				row[i] = k;
				solve(res, n, i + 1, q + 1);
				row[i] = -10000;
			}
		}
		//}
	}
	bool checkDiag(int rows, int k)
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