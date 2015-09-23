#include <string>
using namespace std;

class Solution168
{
public:
	string convertToTitle(int n)
	{
		string res;
		
		while (n)
		{
			int a = (n - 1) % 26;
			res.insert(res.begin(), 'A' + a);
			n = (n-1) / 26;
		}
		return res;
	}
};