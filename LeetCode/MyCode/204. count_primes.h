#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
	//每一个都判断，果断超时了。
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

	//查表法，过了，但是很慢。
	//按着hint修改后到了308ms
	int countPrimes2(int n)
	{
		vector<bool> notPrimes( n, false);
		notPrimes[0] = true;
		notPrimes[1] = true;
		for (int i = 2; i <= sqrt(n) + 1; i++)
		{
			if (!notPrimes[i])//加上这句提速很多。因为如果次数不是质数，则肯定被前面某数乘过，则后面那个数的对应项也被乘过。
			for (int j = i*i; j < n; j++)//还可以从j=i*i开始，因为前面的已经标记过
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

	//16ms。。好快
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