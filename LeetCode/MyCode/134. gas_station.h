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

	//类似于找最大连续子串和，从i开始，到j和<0,则i-j之间的全跳过
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

			if ((i == m - 1 || d == m) && turn)
				return -1;
			if (!turn)
				k++;
		}
		if (k == m)
			return -1;
	}

	//上网搜了下，居然还能从2n降到n,牛逼啊
	//http://www.cnblogs.com/felixfang/p/3814463.html
	int canCompleteCircuit3(vector<int>& gas, vector<int>& cost)
	{
		int size = gas.size();
		int total = 0, sum = 0;
		int start = -1;
		for (int i = 0; i < size; i++)
		{
			total += gas[i] - cost[i];
			sum += gas[i] - cost[i];
			if (sum < 0)
			{
				start = i;
				sum = 0;
			}
		}
		return total < 0 ? -1 : start+1;
	}
};