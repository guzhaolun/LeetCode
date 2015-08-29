class Solution49
{
public:
	double myPow(double x, int n)
	{
		if (n < 0)
		{
			double temp = 1;
			if (n % 2 != 0)
				temp = x;
			return 1 / (myPow(myPow(x, -n / 2), 2)*temp);
		}
		if (n == 0)
			return 1;
		if (n == 1)
			return x;
		if (n == 2)
			return x*x;
		double temp = 1;
		if (n % 2 != 0)
			temp = x;
		return x*myPow(myPow(x, n / 2), 2);
	}
};