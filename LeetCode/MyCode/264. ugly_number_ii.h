#include <vector>
using namespace std;
class Solution264
{
public:
	int nthUglyNumber(int n)
	{
		vector<int> uglys;
		uglys.push_back(1);
		int p2 = 0;
		int p3 = 0;
		int p5 = 0;
		while (uglys.size() < n)
		{
			int p = p2;
			int i = 2;
			if (uglys[p2] * 2 > uglys[p3] * 3)
			{
				p = p3;
				i = 3;
			}
			if (uglys[p] * i > uglys[p5] * 5)
			{
				p = p5;
				i = 5;
			}
			if (i == 2)
				p2++;
			else if (i == 3)
				p3++;
			else
				p5++;
			if (uglys.back() == uglys[p] * i)
				continue;
			uglys.push_back(uglys[p] * i);
		}
		return uglys[n - 1];
	}

	//为啥这个比我的快5倍，感觉一样的啊，是因为用了vector吗？可能是因为指针访问吧。。
	int nthUglyNumber2(int n) {
		if (n <= 0) return 0;

		int *uglyNums = new int[n];
		uglyNums[0] = 1;
		int nextUglyIndex = 1;
		int uglyNum = 1;

		int *t2 = uglyNums, *t3 = uglyNums, *t5 = uglyNums;
		while (nextUglyIndex < n) {
			uglyNum = myMin(*t2 << 1, *t3 * 3, *t5 * 5);
			uglyNums[nextUglyIndex++] = uglyNum;
			if (*t2 << 1 <= uglyNum)
				++t2;
			if (*t3 * 3 <= uglyNum)
				++t3;
			if (*t5 * 5 <= uglyNum)
				++t5;
		}

		delete[] uglyNums;
		return uglyNum;
	}
	int myMin(int a, int b, int c) {
		if (a < b)
			return a < c ? a : c;
		return b < c ? b : c;
	}
};