#include <vector>
using namespace std;

class Solution66
{
public:
	vector<int> plusOne(vector<int>& digits)
	{

		int sum = 0;
		int ones = 0;
		int decade = 1;
		for (int i = digits.size() - 1; i >= 0; i--)
		{
			sum = digits[i] + decade;
			ones = sum % 10;
			decade = sum / 10;
			digits[i] = ones;
		}
		if (decade!=0)
			digits.insert(digits.begin(), decade);
		return digits;
	}
};