//#include <iostream>
//#include <stack>
//#include <string>
//using namespace std;
//bool isValid(string s)
//{
//	stack<char> sta;
//	char temp;
//	for (int i = 0; i < s.length(); i++)
//	{
//		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
//			sta.push(s[i]);
//		else
//		{
//			if (sta.empty())
//				return false;
//			temp = sta.top();
//			sta.pop();
//
//			switch (s[i])
//			{
//			case ')':
//				if (temp != '(')
//					return false;
//				break;
//			case '}':
//				if (temp != '{')
//					return false;
//				break;
//			case ']':
//				if (temp != '[')
//					return false;
//				break;
//			default:
//				break;
//			}
//		}
//	}
//	return sta.empty();
//
//}
//
//int main()
//{
//	string s = "{{}}()(){{{}}}[[]]";
//	cout << isValid(s) << endl;
//	system("pause");
//	return 0;
//}