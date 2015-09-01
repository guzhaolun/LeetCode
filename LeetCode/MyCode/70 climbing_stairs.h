class Solution70
{
public:

	//��ʱ
	int climbStairs(int n) 
	{
		if (n == 0)
			return 0;
		if (n == 1)
			return 1;
		return climbStairs(n - 1) + climbStairs(n - 2);
	}

	//��ʵ����쳲���������
	int climbStairs2(int n)
	{
		if (n == 0)
			return 0;
		if (n == 1||n==2)
			return 1;
		int a = 1;
		int b = 1;
		int c = 0;
		for (int i = 2; i < n; i++)
		{
			c = a + b;
			a = b;
			b = c;
		}
		return c;
	}
};