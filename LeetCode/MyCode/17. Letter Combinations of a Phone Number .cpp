//#include <iostream>
//#include <vector>
//#include <string>
//#include <map>
//using namespace std;
//
//void dfs(string digits, int i, map<int,string> &letters, vector<string>& res,char* temp)
//{
//	
//	if (i == digits.length())
//	{
//		temp[i + 1] = '\0';
//		res.push_back(temp);
//		//temp=temp.substr(0,temp.size()-1);
//		return;
//	}
//
//	int a = digits[i] - '0';
//	for (int j = 0; j < letters[a].length(); j++)
//	{
//		temp[i]=(letters[a][j]);
//		dfs(digits, i + 1, letters, res,temp);
//	}
//}
//
//vector<string> letterCombinations(string digits)
//{
//	
//	map<int, string> letters;
//	letters.insert(make_pair(2, "abc"));
//	letters.insert(make_pair(3, "def"));
//	letters.insert(make_pair(4, "ghi"));
//
//	letters.insert(make_pair(5, "jkl"));
//	letters.insert(make_pair(6, "mno"));
//	letters.insert(make_pair(7, "pqrs"));
//	letters.insert(make_pair(8, "tuv"));
//	letters.insert(make_pair(9, "wxyz"));
//
//	vector<string> res;
//	if (digits.length() == 0)
//		return res;
//	char temp[1000];
//	dfs(digits, 0, letters, res,temp);
//
//	return res;
//}
//
//int main()
//{
//	string s = "234";
//	vector<string> res = letterCombinations(s);
//	system("pause");
//	return 0;
//}