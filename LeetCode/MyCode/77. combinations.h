#include <vector>
using namespace std;

class Solution77
{
public:
	//c(n,k);
	vector<vector<int>> combine(int n,int k)
	{
		vector<int> curr;
		vector<vector<int>> res;
		add(n, k, 1, 0, curr, res);
		return res;
	}

	void add(int n, int k, int index, int deep,vector<int> curr, vector<vector<int>> &res)
	{
		if (deep == k)
		{
			res.push_back(curr);
			return;
		}
		for (int i = index; i < n + 1; i++)
		{
			curr.push_back(i);
			add(n, k, i + 1, deep + 1,curr, res);
			curr.pop_back();
		}
	}
};