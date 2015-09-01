class Solution69 
{
public:
	//二分法
	int mySqrt(int x) 
	{
		if (x <= 0)
			return 0;
		int begin = 0, end = (x+1) / 2;
		while (begin <= end)
		{
			if (begin*begin == x)
				return begin;
			else if (begin*begin < x)
				begin++;
			else
				break;
		}
		return begin-1;
	}
	//牛顿迭代法
	int mySqrt2(int x)
	{
		if (x <= 0)
			return 0;
		double n = x;
		double x1 = 1;
		while (abs(x1*x1 - n) > 0.1)
		{
			x1 = x1 / 2 + n / (x1 * 2);
		}
		return x1;
	}
};