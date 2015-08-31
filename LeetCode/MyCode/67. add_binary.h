#include <string>
#include <algorithm>
using namespace std;
class Solution67{

public:
	string addBinary(string a, string b) {
		int decade = 0;
		int sum = 0;
		int ones = 0;
		int as = a.size(), bs = b.size();
		int size = max(as, bs);
		if (as < bs)
		{
			for (int i = 0; i < bs - as; i++)
				a.insert(a.begin(), '0');
		}
		else
		{
			for (int i = 0; i < (as - bs); i++)
				b.insert(b.begin(), '0');
		}
		for (int i = size - 1; i >= 0; i--)
		{
			int sum = a[i] - '0' + b[i] - '0' + decade;
			b[i] = sum % 2 + '0';
			decade = sum / 2;

		}
		if (decade != 0)
			b.insert(b.begin(), decade + '0');
		return b;
	}
};