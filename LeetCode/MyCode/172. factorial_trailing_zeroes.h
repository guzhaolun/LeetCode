class Solution172
{
public:
	//统计5出现的个数
	int trailingZeros(int n)
	{
		int count = 0;
		int a = 1,i=0;
		while (a)
		{
			i++;
			a=n / pow(5, i);
			count += a;
		}
		return count;
	}
};