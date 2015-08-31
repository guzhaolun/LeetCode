#include <string>
#include <math.h>
using namespace std;
class Solution60 {
public:
	string getPermutation(int n, int k) 
	{
		string res;
		string temp;
		if (k > fac(n) || k < 1)
			return res;
		for (int i = 0; i < n; i++)
			temp.push_back(i + 1+'0');
		int curr = n-1;
		
		for (; curr>0; curr--)
		{
			int i = 1;
			while (k>fac(curr))
			{
				i++;
				k -= fac(curr);
			}
			res.push_back(temp[i-1]);
			temp.erase(temp.begin() + i-1);
		}
		res.push_back(temp[0]);
		return res;
	}

	int fac(int x)
	{
		if (x == 1)
			return 1;
		return x*fac(x - 1);
	}
};