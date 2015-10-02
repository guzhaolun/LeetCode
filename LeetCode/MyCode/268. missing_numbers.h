#include <vector>
using namespace std;

class Solution268
{
public:
	//�Ȳ�������ͼ�ȥ����;��ǣ�
	int missingNumber(vector<int>& nums)
	{
		int sum = 0;
		int i = 0;
		for (; i < nums.size(); i++)
		{
			sum += nums[i];
		}
		int diff = i*(i + 1) / 2 - sum;
		return diff;
	}

	//��0-n��������飬ȱʧ���Ǹ������һ��
	int missingNumber2(vector<int>& nums)
	{
		int res = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			res ^= i;
			res ^= nums[i];
		}
		res ^= nums.size();
		return res;
	}
};