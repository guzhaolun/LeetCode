#include <vector>
using namespace std;

class Solution241
{
public:
	//���η�������95�� unique binary search tree����
	//ÿ�ζ�������벿�ֺ��Ұ벿�ֲ�����
	vector<int> diffWaysToCompute(string input)
	{
		vector<int> res;
		for (int i = 0; i < input.size(); i++)
		{
			if (!isNum(input[i]))
			{
				vector<int> left = diffWaysToCompute(input.substr(0, i));
				vector<int> right = diffWaysToCompute(input.substr(i + 1, input.size()));
				for (int m = 0; m < left.size(); m++)
				{
					for (int n = 0; n < right.size(); n++)
					{
						res.push_back(compute(left[m], right[n], input[i]));
					}
				}
			}
		}
		if (res.empty())
			res.push_back(atoi(input.c_str()));
		return res;
	}

	bool isNum(char s)
	{
		return s >= '0'&&s <= '9';
	}

	int compute(int a, int b, char op)
	{
		if (op == '*')
			return a*b;
		if (op == '-')
			return a - b;
		if (op == '+')
			return a + b;
	}
};