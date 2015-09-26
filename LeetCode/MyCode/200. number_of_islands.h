#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution
{
public:
	//bfs,һ�ι���������
	//������������࣬Ҫ��ֱ�����޸�grid�Ͳ���already�ˡ��õݹ�Ļ����뿴�ż��Щ��
	int numIslands(vector<vector<char>>& grid) 
	{
		int direction[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
		if (grid.empty())
			return 0;
		int m = grid.size();
		int n = grid[0].size();
		queue<pair<int, int>> candi;
		vector<vector<bool>> already(m,vector<bool>(n,false));
		int count = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j]=='1'&&!already[i][j])
				{
					count++;
					candi.push(make_pair(i, j));
					already[i][j] = true;
					while (!candi.empty())
					{
						int x = candi.front().first;
						int y = candi.front().second;
						for (int i = 0; i < 4; i++)
						{
							int x1 = x + direction[i][0];
							int y1 = y + direction[i][1];
							if (x1 >= 0 && x1 < m&&y1 >= 0 && y1 < n&&!already[x1][y1]&&grid[x1][y1]=='1')
							{
								candi.push(make_pair(x1, y1));
								already[x1][y1] = true;
							}
						}
						candi.pop();
					}
				}
			}
		}
		return count;
	}
};