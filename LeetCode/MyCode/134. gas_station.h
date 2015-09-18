#include <vector>
using namespace std;

class Solution134
{
public:
	//直接暴力遍历，超时了
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
	{
		int m = gas.size();
		int k = 0;
		for (; k < m; k++)
		{
			int curr = 0;
			int i = k;
			for (; i < m+k; i++)
			{
				i = i % (m + k);
				curr += gas[i];
				curr -= cost[i];
				if (curr < 0)
					break;
			}
			if (i == m + k)
				return k;
		}
		if (k == m)
			return -1;
	}

	int canCompleteCircuit2(vector<int>& gas, vector<int>& cost)
	{
		int m = gas.size();
		if (m == 0)
			return -1;
		if (m == 1)
		if (gas[0] >= cost[0])
			return 0;
		else
			return -1;
		int k = 0;
		int d = 0;
		while (k < m&&d<m)
		{
			bool turn = false;
			int curr = 0;
			int i = k;
			d = 0;
			for (; i < m + k&&d<m; i++)
			{
				int j = i %m;
				curr += gas[j];
				curr -= cost[j];
				d++;
				if (curr < 0)
				{
					k = (i + 1) % m;
					turn = true;

					break;
				}
			}
			if (d == m && !turn)
				return k;
			if (i == m-1&&turn)
				return -1;
			if (!turn)
				k++;
		}
		if (k == m)
			return -1;
	}
};