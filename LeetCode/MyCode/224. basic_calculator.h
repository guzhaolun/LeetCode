#include <stack>
#include <string>
using namespace std;
class Solution224
{
public:
	int calculate(string s)
	{
		stack<int> numbers;
		stack<char> opers;
		for (int i = s.size()-1; i >= 0;)
		{
			int temp = i;
			while (i>=0&&isNum(s[i]))
				i--;
			if (temp > i)
			{
				int a = atoi(s.substr(i+1, temp - i).c_str());
				numbers.push(a);
				//continue;
			}
			if (i < 0)
				break;
			switch (s[i])
			{
			case ')':
				opers.push(')');
				break;
			case '+':
				opers.push('+');
				break;
			case '-':
				opers.push('-');
				break;
			case '(':
				while (opers.top() != ')')
				{
					int a = numbers.top();
					numbers.pop();
					int b = numbers.top();
					numbers.pop();
					char op = opers.top();
					opers.pop();
					numbers.push(compute(a, b, op));
				}
				opers.pop();
				break;
			default:
				break;
			}
			i--;
		}
		while (!opers.empty())
		{
			int a = numbers.top();
			numbers.pop();
			int b = numbers.top();
			numbers.pop();
			char op = opers.top();
			opers.pop();
			numbers.push(compute(a, b, op));
		}
		return numbers.top();
	}

	int compute(int a, int b, char op)
	{
		if (op == '+')
			return a + b;
		if (op == '-')
			return a - b;
	}
	bool isNum(char a)
	{
		return a <= '9'&&a >= '0';
	}
};