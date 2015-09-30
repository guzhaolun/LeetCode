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

	//2的倍数二进制中只有首位是1.这尼玛。。屌
	bool isPowerOfTwo2(int n) {
		return n > 0 && ((n & (n - 1)) == 0);
	}
};