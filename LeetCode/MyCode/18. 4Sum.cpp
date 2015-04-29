//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//vector<vector<int> > fourSum(vector<int> &num ,int target)
//{
//	sort(num.begin(), num.end());
//	vector<vector<int>> result;
//	vector<int> temp;
//	int a = 0,b=0, j = 0, k = 0;
//	for (int i = 0; i < num.size(); i++)
//	{
//		a = num[i];
//		
//		for (int s = i + 1; s<num.size(); s++)
//		{
//			b = num[s];
//			
//			j = s + 1; k = num.size() - 1;
//			while (j<k)
//			{
//				if (num[j] + num[k] > target-a-b)
//				{
//					k--;
//				}
//				else if (num[j] + num[k] < target-a-b)
//					j++;
//				else
//				{
//					temp.push_back(a);
//					temp.push_back(b);
//					temp.push_back(num[j]);
//					temp.push_back(num[k]);
//					while (k >= 0 && num[k] == num[k - 1])
//						k--;
//					while (j < num.size() && num[j] == num[j + 1])
//						j++;
//					j++;
//					k--;
//					if (!temp.empty())
//					{
//						result.push_back(temp);
//						temp.clear();
//					}
//				}
//			}
//			while (s + 1<num.size() && num[s] == num[s + 1])
//				s++;
//		}
//		while (i + 1<num.size() && num[i] == num[i + 1])
//			i++;
//	}
//	return result;
//}
//
//int main()
//{
//	vector<int> nums{ 1, -2, -5, -4, -3, 3, 3, 5 };
//	vector<vector<int>> res = fourSum(nums, -11);
//	system("pause");
//	return 0;
//}