#include <stack>
#include <string>
#include <queue>
using namespace std;
class Solution227
{
public:
	int calculate(string s)
	{
		stack<int> numbers;
		stack<char> opers;
		queue<char> add;
		for (int i = 0; i < s.size();)
		{
			int temp = i;
			while (isNum(s[i]))
				i++;
			if (temp < i)
			{
				int a = atoi(s.substr(temp, i - temp).c_str());
				numbers.push(a);
				if (!opers.empty() && (opers.top() == '/' || opers.top() == '*'))
				{
					int a = numbers.top();
					numbers.pop();
					int b = numbers.top();
					numbers.pop();
					numbers.push(compute(b, a, opers.top()));
					opers.pop();
				}
			}
			switch (s[i])
			{
			case '+':
			case '-':
				add.push(s[i]);
				break;
			case '/':
			case '*':
				opers.push(s[i]);
				break;
			default:
				break;
			}
			i++;
		}
		stack<int> nums;
		while (!numbers.empty())
		{
			nums.push(numbers.top());
			numbers.pop();
		}
		while (!add.empty())
		{
			int a = nums.top();
			nums.pop();
			int b = nums.top();
			nums.pop();
			char op = add.front();
			add.pop();
			nums.push(compute(a, b, op));
		}
		return nums.top();
	}

	int compute(int a, int b, char op)
	{
		if (op == '+')
			return a + b;
		if (op == '-')
			return a - b;
		if (op == '*')
			return a*b;
		if (op == '/')
			return a / b;
	}
	bool isNum(char a)
	{
		return a <= '9'&&a >= '0';
	}

	//discuss里面一份很简洁的。就是顺序访问，将正负号看成跟数字一体的，这样就一直加。
	int calculate2(string s) {
		istringstream in(s + "+");
		long long total = 0, term, sign = 1, n;
		in >> term;
		char op;
		while (in >> op) {
			if (op == '+' || op == '-') {
				total += sign * term;
				sign = 44 - op; //op == '+' ? 1 : -1
				in >> term;
			}
			else {
				in >> n;
				if (op == '*')
					term *= n;
				else
					term /= n;
			}
		}
		return total;
	}
};