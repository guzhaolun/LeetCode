#include <vector>
#include <algorithm>
using namespace std;

class Solution45
{
public:
	//�õĵݹ��ֳ�ʱ�ˡ�����
	int jump(vector<int>& nums)
	{
		int minStep = INT_MAX;
		step(nums, 0, minStep,0);
		return minStep;
	}

	void step(vector<int>& nums, int index, int& minStep, int currStep)
	{
		currStep++;
		if (nums.size() - index - 1 <= nums[index])
		{
			if (currStep < minStep)
				minStep = currStep;
			return;
		}
		for (int i = nums[index]; i >=1; i--)
			step(nums, index + i, minStep, currStep);
	}

	//O(n)ʱ��ģ�����ţ��,����������������Ӵ����Ǹ�����¼�µ�ÿ��λ�õ����ֵ�ͺ���
	//֤�������������ô˼�������i �Ǵ�i-1 �����ģ���ôiλ�õ��������� <i> = <i-1> +1.
	//���i �Ǵ�i - 2  ��֮ǰ�����ģ���ô<i> = <i - 1>.
	//����֪���ض���<i> >= <i - 1>��
	int jump2(vector<int>& nums)
	{
		int res = 0;
		int curr = 0;
		int last = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (i>last)
			{
				last = curr;
				res++;
			}
			curr = max(curr, i + nums[i]);
		}
		return res;
	}
};