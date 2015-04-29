#include <iostream>
#include <vector>
#include <string>
using namespace std;

void generate(vector<string>& res, string temp, int l, int r, int n)
{
	if (l == n)
	{
		for (int i = 0; i < n - r;i++)
			temp.append(")");
		res.push_back(temp);
		return;
	}
	string s = temp;
	
	generate(res, s.append("("), l + 1, r, n);
	if (l>r)
	{
		s = temp;
		generate(res, s.append(")"), l, r + 1, n);
	}
}
vector<string> generateParenthesis(int n) 
{
	vector<string> res;
	string temp;
	generate(res, temp, 0, 0, n);
	return res;
}

int main()
{
	vector<string> res=generateParenthesis(2);
	system("pause");
	return 0;
}