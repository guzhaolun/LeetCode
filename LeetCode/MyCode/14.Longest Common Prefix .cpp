//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//string longestCommonPrefix(vector<string> &strs) {
//	
//	
//	if (strs.size() == 0)
//		return "";
//
//	string prefix;
//	if (strs[0].length() == 0)
//		return "";
//	char a=strs[0][0];
//	int i = 1, j = 0;
//
//	while (1)
//	{
//
//		while (i<strs.size()&&j<strs[i].length()&&a == strs[i][j])
//		{
//			i++;
//		}
//		if (i == strs.size())
//			j++;
//		else
//			break;
//		i = 1;
//		if (j < strs[0].length())
//			a = strs[0][j];
//		else
//			break;
//	}
//	return strs[0].substr(0,j);
//}
//
//int main()
//{
//	vector<string> strs;
//	strs.push_back("abcd");
//	strs.push_back("abdf");
//	strs.push_back("aba");
//	cout << longestCommonPrefix(strs) << endl;
//	system("pause");
//	return 0;
//}