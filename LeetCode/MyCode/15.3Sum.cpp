//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//vector<vector<int> > threeSum(vector<int> &num)
//{
//	sort(num.begin(), num.end());
//	vector<vector<int>> result;
//	vector<int> temp;
//	int a = 0, j = 0, k = 0;
//	for (int i = 0; i < num.size(); i++)
//	{
//		
//		 a = num[i];
//		if (a>0)
//			break;
//		j = i + 1; k = num.size() - 1;
//		while (j<k)
//		{
//			if (num[j] + num[k] > -a)
//			{
//				k--;
//			}
//			else if (num[j] + num[k] < -a)
//				j++;
//			else 
//			{
//				temp.push_back(a);
//				temp.push_back(num[j]);
//				temp.push_back(num[k]);
//				while (k>=0&&num[k] == num[k - 1])
//					k--;
//				while (j<num.size()&&num[j] == num[j + 1])
//					j++;
//				j++;
//				k--;
//				if (!temp.empty())
//				{
//					result.push_back(temp);
//					temp.clear();
//				}
//			}
//		}
//		while (i + 1<num.size() && num[i] == num[i + 1])
//			i++;
//	}
//	return result;
//}
//
//int main()
//{
//	vector<int> nums{ -1, 0, 1, 2, - 1, - 4 };
//	vector<vector<int>> res = threeSum(nums);
//	system("pause");
//	return 0;
//}