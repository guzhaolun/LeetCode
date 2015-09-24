#include <iostream>
using namespace std;
class Solution191 {
public:
	int hammingWeight(unsigned int n) {
		int count = 0;
		while (n)
		{
			count += n & 1;
			n = n >> 1;
		}
		return count;
	}

	//这东西居然还有更快的，牛逼啊
	int hammingWeight(unsigned int n)
	{
		int count = 0;
		while (n)
		{
			n = n&(n - 1);
			count++;
		}
		return count;
	}
};