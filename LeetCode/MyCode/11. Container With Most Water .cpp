//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int maxArea(vector<int> &height) {
//
//	int left = 0, right = height.size() - 1;
//	int maxarea = 0;
//	int area = 0;
//	while (left < right)
//	{
//		area = min(height[left], height[right])*(right - left + 1);
//		if (area>maxarea)
//			maxarea = area;
//		if (height[left] < height[right])
//			left++;
//		else
//			right--;
//	}
//	return maxarea;
//}
//
//int main()
//{
//	return 0;
//}