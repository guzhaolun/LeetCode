//#include <iostream>
//#include <string>
//using namespace std;
//string convert(string s, int nRows) 
//{
//	string result = "";
//	int span = 2 * nRows - 2;
//	if (s.length() < 3 || nRows == 1 ||s.length()<nRows)
//		return s;
//	for (int i = 0; i < nRows; i++)
//	{
//		//result.push_back(s[0]);
//		for (int j = i; j < s.length(); j += span)
//		{
//			result.push_back(s[j]);
//			if (i>0 && i < nRows - 1 && 2 * nRows - 2 * i + j - 2<s.length())
//			{
//				result.push_back(s[2 * nRows - 2*i+j - 2]);
//			}
//		}
//	}
//	return result;
//}
//int main()
//{
//	string s = "PAYPALISHIRING";
//	string s1 = "0123456789abcf";
//	string result=convert(s1, 3);
//	cout << result << endl;
//	system("pause");
//	return 0;
//}