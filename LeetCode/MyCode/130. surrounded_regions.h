#include <vector>
#include <queue>
using namespace std;
class Solution130
{
public:
	//从边界的‘O'开始向中间延伸，标记，没延伸到的都更改
	void solve(vector<vector<char>>& board)
	{
		int m = board.size();
		if (m == 0)
			return;
		int n = board[0].size();
		vector < vector < bool>> change(m, vector<bool>(n, false));
		queue<pair<int, int>> candicate;
		for (int i = 0; i < n; i++)
		{
			if (board[0][i] == 'O' && !change[0][i])
			{
				candicate.push(make_pair(0, i));
				change[0][i] = true;
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (board[m - 1][i] == 'O' && !change[m - 1][i])
			{
				candicate.push(make_pair(m - 1, i));
				change[m - 1][i] = true;
			}
		}
		for (int i = 1; i < m; i++)
		{
			if (board[i][0] == 'O' && !change[i][0])
			{
				candicate.push(make_pair(i, 0));
				change[i][0] = true;
			}
		}
		for (int i = 1; i < m; i++)
		{
			if (board[i][n - 1] == 'O' && !change[i][n - 1])
			{
				candicate.push(make_pair(i, n - 1));
				change[i][n - 1] = true;
			}
		}
		while (!candicate.empty())
		{
			int s = candicate.front().first;
			int t = candicate.front().second;
			if (t + 1 < n&&board[s][t + 1] == 'O'&&!change[s][t + 1])
			{
				candicate.push(make_pair(s, t + 1));
				change[s][t + 1] = true;
			}
			if (t > 0 && board[s][t - 1] == 'O'&&!change[s][t - 1])
			{
				candicate.push(make_pair(s, t - 1));
				change[s][t - 1] = true;
			}
			if (s + 1 < m&&board[s + 1][t] == 'O'&&!change[s + 1][t])
			{
				candicate.push(make_pair(s + 1, t));
				change[s + 1][t] = true;
			}
			if (s > 0 && board[s - 1][t] == 'O'&&!change[s - 1][t])
			{
				candicate.push(make_pair(s - 1, t));
				change[s - 1][t] = true;
			}
			candicate.pop();
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == 'O'&&change[i][j] == false)
					board[i][j] = 'X';
			}
		}
	}
};