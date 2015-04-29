//#include <iostream>
//using namespace std;
////bool isMatch(const char* s, const char* p)
////{
////	int i = 0, j = 0;
////	while (s[i] != '\0'&&p[j]!='\0')
////	{
////		if (s[i] == '\0' || p[j] == '\0')
////			break;
////		if (p[j] == '.'&&p[j + 1] == '*')
////		{
////			j += 2;
////			while (s[i] != p[j]&&s[i]!='\0')
////				i++;
////		}
////		while (p[j] != '.'&& s[i] != p[j] && p[j + 1] == '*')
////			j+=2;
////		if (p[j] != '.'&& s[i] != p[j])
////			return false;
////		
////		if (s[i] == '\0'&&p[j] == '\0')
////			return true;
////		if (s[i] == p[j] || p[j] == '.')
////		{
////			if (s[i+1] == p[j+1])
////			{
////				if (s[i + 1] == '\0')
////					return true;
////				i++;
////				j++;
////			}
////			else if (p[j + 1] == '.')
////			{
////				i++;
////				j++;
////
////			}
////			else if (s[i + 1] == '\0' || p[j + 1] == '\0')
////				return false;
////			else
////				j++;
////		}
////		//j++;
////		if (p[j] == '*')
////		{
////			while (s[i] == s[i + 1])
////				i++;
////			i++;
////			j++;
////		}
////		//if (s[i + 1] != '\0')
////		//	i++;
////		///if (p[j + 1] != '\0')
////		//	j++;
////	}
////	if (s[i] == '\0'&&p[j]=='\0')
////		return true;
////	else
////		return false;
////}
//
//bool isMatch(const char *s, const char *p) {
//	// Start typing your C/C++ solution below  
//	// DO NOT write int main() function 
//	//这个递归太屌了，搞循环快搞死了，主要是a*a匹配aaa之类的好困难。。。
//	if (*p == 0) return *s == 0;
//	if (*(p + 1) != '*')
//	{
//		if (*s != 0 && (*p == *s || *p == '.')) return isMatch(s + 1, p + 1);
//		else return false;
//	}
//	else
//	{
//		// *s == *p  
//		while (*s != 0 && (*s == *p || *p == '.'))
//		{
//			if (isMatch(s, p + 2)) return true;
//			s++;
//		}
//		return (isMatch(s, p + 2));
//	}
//}
//
//int main()
//{
//	const char *s = "abc";
//	const char* p = ".*";
//	cout << isMatch(s, p) << endl;
//	system("pause");
//	return 0;
//}