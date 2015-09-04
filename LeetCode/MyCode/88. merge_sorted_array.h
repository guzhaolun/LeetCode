#include <vector>
using namespace std;

class Solution88
{
public:

	//��ǰ�����ǣ�������Ҫ����ľͺ��ƺ��������
	void merge(vector<int> &num1, int m, vector<int>& num2, int n)
	{
		int i = 0, j = 0, k = m, t=0;
		while (t<m &&j < n)
		{
			if (num1[i] <= num2[j])
			{
				i++;
				t++;
			}
			else
			{
				for (int s = k; s>i; s--)
				{
					num1[s] = num1[s - 1];
				}
				num1[i] = num2[j];
				k++;
				j++;
				i++;
			}
		}
		while (k!= m + n )
		{
			for (int s = k; s>i; s--)
			{
				num1[s] = num1[s - 1];
			}
			num1[i] = num2[j];
			k++;
			j++;
			i++;
		}
	}

	//�Ӻ���ǰɨ�棬�����ƶ�����, ����Ϊë����ʱ�������������
	//���²�һ����һ���ˣ�ë��
	void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		int i = m - 1, j = n - 1, k = m + n - 1;
		while (i >= 0 && j >= 0)
		{
			if (nums1[i] <= nums2[j])
				nums1[k--] = nums2[j--];
			else
				nums1[k--] = nums1[i--];
		}
		while (j >= 0)
			nums1[k--] = nums2[j--];
	}
};