//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int threeSumClosest(vector<int> &num, int target) 
//{
//	sort(num.begin(), num.end());
//	int sum=0;
//	vector<int> temp;
//	int a = 0, j = 0, k = 0, error=0, minerror=INT_MAX;
//	for (int i = 0; i < num.size(); i++)
//	{
//
//		a = num[i];
//	
//		j = i + 1; k = num.size() - 1;
//		while (j<k)
//		{
//			error = abs(a + num[j] + num[k] - target);
//			if (error<minerror)
//			{
//				minerror = error;
//				sum =(a + num[j] + num[k]);
//			}
//			if (abs(a + num[j + 1] + num[k] - target) < abs(a + num[j] + num[k - 1] - target))
//			{
//				j++;
//			}
//			else
//				k--;
//			
//		}
//	
//	}
//	return sum;
//}
//
//int main()
//{
//	vector<int> nums{ 1, 1, -1, -1, 3 };
//	int res = threeSumClosest(nums,-1);
//	system("pause");
//	return 0;
//}