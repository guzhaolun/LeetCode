#include <iostream>
#include <vector>
using namespace std;

class Solution233
{
public:
	//先找一位数两位数，三位数分别最多有多少个1，然后从高位到低位循环累加。
	int countDigitOne(int n)
	{
		int count = 0;
		int temp = n;
		int last = 0;
		int power = 0;
		vector<int> ones;
		if (n <= 0)
			return 0;
		else if (n < 10)
			return 1;
		ones.push_back(0);
		while (temp>=10)
		{
			last = last * 10 + pow(10, power);
			temp /= 10;
			power++;
			ones.push_back(last);
		}

		for (int i = power; i >= 0; i--)
		{
			int base = pow(10, i);
			if (n / base > 1)
			{
				count += base;
				count += n / base*ones[i];
			}
			if (n / base == 1)
			{
				count += n%base+1;
				count += ones[i];
			}
			n = n%base;
		}
		return count;
	}

	//http://blog.csdn.net/xudli/article/details/46798619
	//每10个数, 有一个个位是1, 每100个数, 有10个十位是1, 每1000个数, 有100个百位是1.  做一个循环, 每次计算单个位上1得总个数(个位,十位, 百位).  
	int countDigitOne2(int n) {
		int ones = 0;
		for (long m = 1; m <= n; m *= 10) {
			long a = n / m, b = n%m;
			ones += (a + 8) / 10 * m;
			if (a % 10 == 1) ones += b + 1;
		}
		return ones;
	}
};