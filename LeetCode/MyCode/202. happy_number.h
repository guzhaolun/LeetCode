#include <unordered_set>
using namespace std;

class Solution202
{
public:
	bool isHappy(int n)
	{
		unordered_set<int> already;
		int m = n;
		while (m)
		{
			n = m;
			m = 0;
			while (n)
			{
				int a = n % 10;
				n = n / 10;
				m += a*a;
			}
			if (m == 1)
				return true;
			if (already.find(m) == already.end())
				already.insert(m);
			else
				return false;
		}
	}
};