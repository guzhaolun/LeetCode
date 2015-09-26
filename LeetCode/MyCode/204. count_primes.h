#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
	//ÿһ�����жϣ����ϳ�ʱ�ˡ�
	int countPrimes(int n)
	{
		int count = 0;
		for (int i = 2; i <= n; i++)
		{
			if (isPrime(i))
				count++;
		}
		return count;
	}

	bool isPrime(int n)
	{
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n%i == 0)
				return false;
		}
		return true;
	}

	//��������ˣ����Ǻ�����
	//����hint�޸ĺ���308ms
	int countPrimes2(int n)
	{
		vector<bool> notPrimes( n, false);
		notPrimes[0] = true;
		notPrimes[1] = true;
		for (int i = 2; i <= sqrt(n) + 1; i++)
		{
			if (!notPrimes[i])//����������ٺܶࡣ��Ϊ�������������������϶���ǰ��ĳ���˹���������Ǹ����Ķ�Ӧ��Ҳ���˹���
			for (int j = i*i; j < n; j++)//�����Դ�j=i*i��ʼ����Ϊǰ����Ѿ���ǹ�
				notPrimes[j] = true;
		}
		int count = 0;
		for (int i = 2; i < n; i++)
		{
			if (!notPrimes[i])
				count++;
		}
		return count;
	}

	//16ms�����ÿ�
	int countPrimes3(int n)
	{
		if (n <= 2) return 0;
		int res = n >> 1, m = sqrt(n - 1); // intilize res to n/2, removes all even number(not 2) and 1
		bool *table = new bool[n];
		for (int i = 3, j, step; i <= m; i += 2)
		if (!table[i]) { // i is an odd prime
			for (step = i << 1, j = i*i; j<n; j += step) // step=i*2, ignore even numbers
			if (!table[j]) { table[j] = 1; --res; }
		}
		delete[]table;
		return res;
	}
};