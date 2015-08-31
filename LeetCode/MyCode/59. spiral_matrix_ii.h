#include <vector>
using namespace std;

class Solution59
{
public:
	vector<vector<int>> generateMatrix(int n)
	{
		int i = 0, j = -1;
		vector<vector<int>> a(n, vector<int>(n, 0));

		int now = 1;
		while (now<=n)
		{

			while (j + 1 < n && !a[i][j + 1])
			{
				j++;
				a[i][j] = now;
				now++;
			}

			while (i + 1 < n && !a[i + 1][j])
			{
				i++;
				a[i][j] = now;
				now++;
			}

			while (j >= 1 && !a[i][j - 1])
			{
				j--;
				a[i][j] = now;
				now++;
			}

			while (i >= 1 && !a[i - 1][j])
			{
				i--;
				a[i][j] = now;
				now++;
			}

		}
		return a;
	}
};