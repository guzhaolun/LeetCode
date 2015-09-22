#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution150
{
public:
	int evalRPN(vector<string>& tokens)
	{
		stack<int> nums;
		for (int i = 0; i < tokens.size(); i++)
		{
			if (tokens[i].size() == 1 && (tokens[i][0]<'0' || tokens[i][0]>'9'))
			{
				int b = nums.top();
				nums.pop();
				int a = nums.top();
				nums.pop();

				switch (tokens[i][0])
				{
				case '+':
					nums.push(a + b);
					break;
				case '-':
					nums.push(a - b);
					break;
				case '*':
					nums.push(a*b);
					break;
				case '/':
					nums.push(a / b);
					break;
				default:
					break;
				}

			}
			else
			{
				nums.push(atoi(tokens[i].c_str()));
			}
		}
		if (nums.size() == 1)
			return nums.top();
	}
};