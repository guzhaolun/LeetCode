class Solution
{
public:
	//�ҵ���ͬ��ǰKλ���ɣ�����and�϶�Ϊ0��
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

	//���ּ�Ȼ������ͬ��ǰ��λ���Ǿ�û��Ҫ�ǵô�ǰ�����ң��Ӻ���ǰ����ࡣ��������ٶȱ���һ�������ٰ�����������Ϊm,n����Ƚϴ󣬴Ӻ���ǰ��Ҫ�ҵĸ��ࡣ
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