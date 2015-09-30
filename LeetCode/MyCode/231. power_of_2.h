#include <iostream>
using namespace std;

class Solution231
{
public:
	bool isPowerOfTwo(int n) 
	{
		if (n<1)
			return false;
		if (n == 1)
			return true;
		while (n % 2 == 0)
		{
			n = n / 2;
			if (n == 1)
				return true;
		}
		return false;
	}

	//2�ı�����������ֻ����λ��1.�����ꡣ����
	bool isPowerOfTwo2(int n) {
		return n > 0 && ((n & (n - 1)) == 0);
	}
};