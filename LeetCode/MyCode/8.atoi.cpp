//#include <iostream>
//using namespace std;
//
//int atoi(string s)
//{
//	int res = 0, temp = 0;
//	bool neg = false;
//	int begin = 0,end=s.length()-1;
//	while (isspace(s[begin]))
//		begin++;
//	while (s[begin]<'0' || s[begin]>'9' )
//	{
//		if (s[begin] != '+' && s[begin] != '-')
//			return 0;
//		else
//			break;
//	}
//	while (s[end]<'0' || s[end]>'9')
//	{
//		end--;
//	}
//	if (s[begin]<'0' || s[begin]>'9')
//	{
//		neg = true;
//		begin++;
//	}
//	for (int i = begin; i < end; i++)
//	{
//		if (s[i]<'0' || s[i]>'9')
//		{
//			end = i-1;
//			break;
//		}
//	}
//	if (neg)
//	if (s[begin - 1] == '-')
//		neg = true;
//	else
//		neg = false;
//	for (int i = end; i >=begin ;i--)
//	{
//		if (s[i]<'0' || s[i]>'9')
//			return 0;
//		temp = s[i] - '0';
//		if (temp > 2 && (end - i) > 8||temp!=0&&(end-i)>9)
//		{
//			if (!neg)
//				return INT_MAX;
//			else
//				return INT_MIN;
//		}
//		temp=temp*pow(10, (end - i)); 
//		if (!neg && INT_MAX - res <= temp)
//			return INT_MAX;
//		else if (neg && (INT_MIN + res)>=-temp)
//			return INT_MIN;
//		res += temp;
//	}
//	
//	if (neg)
//	if (s[begin-1] == '-')
//		res = -res;
//	return res;
//}
//
//int main()
//{
//	string s = "    +11191657170";
//	cout << atoi(s) << endl;
//	system("pause");
//	return 0;
//}