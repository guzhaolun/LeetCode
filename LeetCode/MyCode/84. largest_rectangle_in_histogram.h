#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution84
{
public:

	//遍历，但是做了剪纸，对递减序列不做判断。
	int largestRectangleArea(vector<int>& height)
	{
		int area = 0;
		for (int i = 0; i < height.size(); i++) {
			for (int k = i + 1; k < height.size(); k++) {
				if (height[k] < height[k - 1]) {
					i = k - 1;
					break;
				}
				else {
					i = k;
				}
			}
			int lowest = height[i];
			for (int j = i; j >= 0; j--) {
				if (height[j] < lowest) {
					lowest = height[j];
				}
				int currArea = (i - j + 1) * lowest;
				if (currArea > area) {
					area = currArea;
				}
			}
		}
		return area;
	}

	int largestRectangleArea2(vector<int>& height)
	{
		if (height.empty())
			return 0;
		height.push_back(0);
		stack<int> hs;
		int maxA = INT_MIN;
		for (int i = 0; i < height.size(); i++)
		{
			if (hs.empty() || height[i]>height[hs.top()])
				hs.push(i);
			else
			{
				int temp = hs.top();
				hs.pop();
				int area = height[temp] * (hs.empty() ? i : i - hs.top() - 1);
				maxA = max(maxA, area);
				i--;
			}
		}
		return maxA;
	}
};