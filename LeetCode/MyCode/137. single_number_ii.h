#include <vector>
using namespace std;

class Solution {
public:
	int singleNumber(int A[], int n) {
		int one = 0, two = 0, three = 0;
		for (int i = 0; i<n; i++){
			two |= one&A[i];
			one ^= A[i];
			three = one&two;
			one &= ~three;
			two &= ~three;
		}
		return one;
	}
};

class Solution {
public:
	int singleNumber(int A[], int n) {
		int bitnum[32] = { 0 };
		int res = 0;
		for (int i = 0; i<32; i++){
			for (int j = 0; j<n; j++){
				bitnum[i] += (A[j] >> i) & 1;
			}
			res |= (bitnum[i] % 3) << i;
		}
		return res;
	}
};