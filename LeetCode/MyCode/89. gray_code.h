#include <vector>
using namespace std;

class Solution89
{
public:
	vector<int> grayCode(int n)
	{
		vector<bool> binary(n,false);
		vector<int> res;
		if (n == 0)
			return res;
		vector<bool> already(pow(2,n), false);
		res.push_back(0);
		already[0] = true;
		recursive(binary, res, already, n, 1);
		return res;
	}

	//递归寻找所有情况，结果会很慢。、
	bool recursive(vector<bool>& binary, vector<int>& res, vector < bool>& already, int n, int index)
	{
		if (pow(2, n) == index)
		{
			return true;
		}
		for (int i = n-1; i >=0; i--)
		{
			binary[i] = (binary[i] ? false : true);
			int temp = binary2Oct(binary);
			if (!already[temp])
			{
				already[temp] = true;
				res.push_back(temp);
				if (recursive(binary, res, already, n, index + 1))
					return true;
			}
			else
			{
				binary[i] = (binary[i] ? false : true);
			}
			//res.pop_back();
		}
	}

	int binary2Oct(vector<bool>& binary)
	{
		int res = 0;
		int n = binary.size();
		for (int i = 0; i < n; i++)
		{
			if (binary[i])
			res += pow(2, n-i-1);
		}
		return res;
	}

	//利用移位操作，牛逼啊
	//Gray Code : 000, 001, 011, 010, 110, 111, 101, 100, 最右边值为 “1” 的bit在最左边了，结束。

	//Binary    : 000, 001, 010, 011, 100, 101, 110, 111
	vector<int> grayCode2(int n)
	{
		vector<int> res;
		int size = 1<<n;
		res.resize(size);
		for (int i = 0; i < size; i++)
		{
			int gray = i^i>>1;
			res[i] = gray;
		}
		return res;
	}
};