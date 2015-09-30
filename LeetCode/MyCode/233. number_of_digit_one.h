#include <iostream>
#include <vector>
using namespace std;

class Solution233
{
public:
	//����һλ����λ������λ���ֱ�����ж��ٸ�1��Ȼ��Ӹ�λ����λѭ���ۼӡ�
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
	//ÿ10����, ��һ����λ��1, ÿ100����, ��10��ʮλ��1, ÿ1000����, ��100����λ��1.  ��һ��ѭ��, ÿ�μ��㵥��λ��1���ܸ���(��λ,ʮλ, ��λ).  
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