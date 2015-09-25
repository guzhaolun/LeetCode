#include <iostream>
using namespace std;
class Solution190 {
public:
	unsigned int reverseBits(unsigned int n)
	{
		unsigned int res=0;
		for (int i = 0; i < 32; i++)
		{
			res = res<< 1 | n & 1;
			n = n >> 1;
		}
		return res;
	}
};