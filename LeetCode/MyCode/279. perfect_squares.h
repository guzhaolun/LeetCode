#include <iostream>
using namespace std;

class Solution279
{
public:
	//每种都列出来，超时了。
	int numSquares(int n)
	{
		int s = sqrt(n);
		int deep = 0;
		vector<int> res;
		add(n, 0, s, deep, res);
		int least = *min_element(res.begin(), res.end());
		return least;
	}

	void add(int n, int currSum, int start, int deep, vector<int>& res)
	{
		for (int i = start; i >= 1; i--)
		{
			if (currSum>n)
				return;
			if (currSum == n)
			{
				res.push_back(deep);
				return;
			}
			add(n, currSum + i*i, i, deep + 1, res);
		}
	}

	//动态规划，每个数都是去掉一个平方数之后剩余的数用的最少的平方数。
	int numSquares2(int n)
	{
		int s = sqrt(n);
		vector<int> dp(n + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j *j <= i; j++)
			{
				dp[i] = min(dp[i], 1 + dp[i - j*j]);
			}
		}
		return dp[n];
	}
	//https://leetcode.com/discuss/58056/summary-of-different-solutions-bfs-static-and-mathematics
	//discuss里面看到的，用了静态数组，因为测试时多次调用，之前的结果保存了。。。所以提升很多。。本质上一样的。
	int numSquares3(int n)
	{
		if (n <= 0)
		{
			return 0;
		}

		// cntPerfectSquares[i] = the least number of perfect square numbers 
		// which sum to i. Since cntPerfectSquares is a static vector, if 
		// cntPerfectSquares.size() > n, we have already calculated the result 
		// during previous function calls and we can just return the result now.
		static vector<int> cntPerfectSquares({ 0 });

		// While cntPerfectSquares.size() <= n, we need to incrementally 
		// calculate the next result until we get the result for n.
		while (cntPerfectSquares.size() <= n)
		{
			int m = cntPerfectSquares.size();
			int cntSquares = INT_MAX;
			for (int i = 1; i*i <= m; i++)
			{
				cntSquares = min(cntSquares, cntPerfectSquares[m - i*i] + 1);
			}

			cntPerfectSquares.push_back(cntSquares);
		}

		return cntPerfectSquares[n];
	}

	//利用拉格朗日的4平方理论。。。
private:
	int is_square(int n)
	{
		int sqrt_n = (int)(sqrt(n));
		return (sqrt_n*sqrt_n == n);
	}

public:
	// Based on Lagrange's Four Square theorem, there 
	// are only 4 possible results: 1, 2, 3, 4.
	int numSquares4(int n)
	{
		// If n is a perfect square, return 1.
		if (is_square(n))
		{
			return 1;
		}

		// The result is 4 if n can be written in the 
		// form of 4^k*(8*m + 7).
		while ((n & 3) == 0) // n%4 == 0  
		{
			n >>= 2;
		}
		if ((n & 7) == 7) // n%8 == 7
		{
			return 4;
		}

		// Check whether 2 is the result.
		int sqrt_n = (int)(sqrt(n));
		for (int i = 1; i <= sqrt_n; i++)
		{
			if (is_square(n - i*i))
			{
				return 2;
			}
		}

		return 3;
	}
};