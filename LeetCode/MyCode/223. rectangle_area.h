#include <algorithm>
using namespace std;
class Solution {
public:
	//总的减去重合的。
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int common;
		if (C <= E || G <= A || D <= F || H <= B)
			common = 0;
		else
		{
			int a, b, c, d;
			a = max(A, E);
			b = max(B, F);
			c = min(C, G);
			d = min(D, H);
			common = (d - b)*(c - a);
		}
		return (D - B)*(C - A) + (H - F)*(G - E) - common;
	}
};