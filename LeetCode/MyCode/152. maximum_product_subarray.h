#include <vector>
#include <algorithm>
using namespace std;

class Solution152
{
public:
	//֪���Ƕ�̬�滮��ת�Ʒ���û��ã����˺ü������,������Щû��ͨ�������������±��˵ĺü�ࡣ��
	int maxProduct(vector<int>& nums)
	{
		int maxVal = INT_MIN;
		int curr = 1;
		int negCurr = 1;
		for (int i = 0; i < nums.size(); i++)
		{
			bool change = false;
			if (nums[i]>0)
			{
				curr *= nums[i];
				change = true;
			}
			else
				curr = 1;
			
			negCurr *= nums[i];
			if (change)
				maxVal = max(maxVal, curr);
			maxVal = max(maxVal, negCurr);
			curr = max(negCurr, curr);
			negCurr = min(negCurr,nums[i]);
			
			if (curr<1 && curr>-1)
				curr = 1;

		}
		return maxVal;
	}

	int maxProduct2(vector<int>& nums)
	{
		if (nums.empty())
			return 0;

		int maxVal = INT_MIN;
		int currMax=1;
		int currMin=1;
		for (int i = 0; i < nums.size(); i++)
		{
			int a = currMax*nums[i];
			int b = currMin*nums[i];
			currMax = max(max(a, b), nums[i]);
			currMin = min(min(a, b), nums[i]);
			maxVal = max(maxVal, currMax);
		}
		return maxVal;
	}
};