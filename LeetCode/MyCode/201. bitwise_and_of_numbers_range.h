class Solution
{
public:
	//找到相同的前K位即可，后面and肯定为0；
	int rangeBitwiseAnd(int m, int n)
	{
		int m1 = m, n1 = n;
		int res = 0;

		int count = 0;
		int x = n;
		while (x)
		{
			count++;
			x = x >> 1;
		}
		for (int i = count - 1; i >= 0; i--)
		{
			m1 = m >> i;
			n1 = n >> i;
			if (m1 == n1)
				res = m1;
			else
			{
				res = res << i + 1;
				return res;
			}
		}
		return res;
	}

	//发现既然是找相同的前几位，那就没必要非得从前往后找，从后往前更简洁。不过这个速度比上一个慢不少啊，可能是因为m,n相隔比较大，从后往前需要找的更多。
	int rangeBitwiseAnd2(int m, int n) {
		int offset = 0;
		while (m && n)
		{
			if (m == n)
			{
				return m << offset;
			}
			m >>= 1;
			n >>= 1;
			offset++;
		}

		return 0;
	}
};