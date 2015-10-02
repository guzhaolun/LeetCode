#include <vector>
using namespace std;
class Solution260
{
public:
	//�ֳ����飬ÿ��2*n+1�������ͳ���single number 1;
	//���������϶�����ͬ��������������ҵ�������෴�����λ�����ݴ�λ�����ݷ�Ϊ����ֱ����
	vector<int> singleNumber(vector<int>& nums)
	{
		int len = nums.size();
		int AxorB = 0;
		for (int i = 0; i<len; i++){
			AxorB ^= nums[i];
		}
		int mask = AxorB & (~(AxorB - 1));
		int A = 0;
		int B = 0;
		for (int i = 0; i<len; i++){
			if ((mask&nums[i]) == 0){
				A ^= nums[i];
			}
			else{
				B ^= nums[i];
			}
		}
		return vector<int>({ A, B });
	}
};