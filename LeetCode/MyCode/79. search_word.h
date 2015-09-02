#include <vector>
#include <string>
using namespace std;

class Solution79
{
public:
	bool exist(vector<vector<char>>& board, string word)
	{
		if (board.empty())
			return false;
		int m = board.size();
		int n = board[0].size();
		vector<vector<bool>> record(m, vector<bool>(n, false));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == word[0])
				{
					if (walk(board, record, word, 0, i, j, m, n))
						return true;
				}
				else
					continue;
			}
		}
		return false;
	}

	//本地测着没问题啊，就是过不了，日了狗了。
	//record用传值就没事，但是会超时，传引用就会出错。。
	bool walk(vector<vector<char>>& board, vector<vector<bool>>& record, string word, int index, int i, int j, int m, int n)
	{

		if (i<0 || j<0 || i>m - 1 || j>n - 1)
			return false;
		if ((board[i][j] == (char)word[index]) && !record[i][j])
		{
			;
		}
		else
			return false;

		index++;
		if (index == word.size())
			return true;
		record[i][j] = true;
		if (!walk(board, record, word, index, i, j + 1, m, n))
		{
			if (!walk(board, record, word, index, i + 1, j, m, n))
			{
				if (!walk(board, record, word, index, i, j - 1, m, n))
				{
					if (!walk(board, record, word, index, i - 1, j, m, n))
					{
						return false;
					}
				}
			}
		}
		record[i][j] = false;
	}


	//这个为啥就没事呢，奇了怪了。
int Dir[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

	//DFS Find the path
public:

	void DFS(int curX, int curY, int curPos, vector<vector<bool>>& visit,
		bool& OK, vector<vector<char>> &board, string& word)
	{
		if (OK) return;
		if (word[curPos] != board[curX][curY]) return;
		if (curPos == word.size() - 1)
		{
			OK = true;
			return;
		}
		for (int d = 0; d < 4; ++d)
		{
			int nextX = curX + Dir[d][0];
			int nextY = curY + Dir[d][1];
			if (nextX >= 0 && nextX < board.size() && nextY >= 0 && nextY < board[0].size())
			{
				if (!visit[nextX][nextY])
				{
					visit[nextX][nextY] = true;
					DFS(nextX, nextY, curPos + 1, visit, OK, board, word);
					visit[nextX][nextY] = false;
				}
			}

		}
	}
public:
	bool exist(vector<vector<char> > &board, string word) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (word.size() == 0) return false;
		if (board.size() == 0 || board[0].size() == 0) return false;
		bool OK = false;
		vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));
		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[i].size(); ++j)
			{
				visit[i][j] = true;
				DFS(i, j, 0, visit, OK, board, word);
				visit[i][j] = false;
				if (OK) return true;
			}
		}

		return false;
	}
};