//#include <iostream>
//#include <string>
//using namespace std;
//
//	int romanToInt(string s)
//	{
//		int values[13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
//		string numerals[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
//		int result = 0;
//		for (int i = 0; i < s.length(); )
//		{
//			for (int j = 0; j < 13; j++)
//			{
//				if (s.substr(i, 2) == numerals[j])
//				{
//					result += values[j];
//					i += 2;
//					break;
//				}
//				else if (s.substr(i, 1) == numerals[j])
//				{
//					result += values[j];
//					i++;
//					break;
//				}
//			}
//		}
//		return result;
//	}
//
//	int main()
//	{
//		int result = romanToInt("MMMCCCXXXIII");
//		cout << result << endl;
//
//		system("pause");
//		return 0;
//	}