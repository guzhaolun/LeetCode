#include <vector>
#include <algorithm>
using namespace std;
class Solution216 {
public:
	
	vector<vector<int> > combinationSum3(int k, int n)
	{
		vector<int> curr;
		vector<vector<int>> res;
		if (k*(k + 1) / 2>n)
			return res;
		sum(curr,k,1, 0, n, res);
		return res;
	}

	void sum(vector<int>& curr,int k,int start, int currSum, int n, vector<vector<int>>& res)
	{
		if (currSum == n&&curr.size()==k)
		{
			res.push_back(curr);
			return;
		}
		for (int i = start; i < 10; i++)
		{
			if (currSum + i>n||curr.size()>k-1)
				break;
			curr.push_back(i);
			sum(curr, k,i+1, currSum+i, n, res);
			curr.pop_back();
		}
	}
};