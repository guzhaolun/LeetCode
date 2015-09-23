#include <vector>
using namespace std;

class Solution169
{
public:

	//������hash,�Լ�û�ҵ���Ч�ġ�
	//���Ǳ��˵ģ��ҵ���ͬ��Ԫ�ؾͳɶ�ɾ�������ʣ�µĿ϶��ǣ�̫���ˡ�����
	int majorityElement(vector<int>& nums)
	{
		int res;
		int count=0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (count == 0)
			{
				res = nums[i];
				count++;
			}
			else
			{
				if (nums[i] == res)
					count++;
				else
					count--;
			}
		}
		return res;
	}
};