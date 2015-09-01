#include <vector>
using namespace std;

class Solution74
{
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target)
	{
		if (matrix.empty())
			return false;
		int m = matrix.size();
		int n = matrix[0].size();
		int low = 0, high = m - 1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (matrix[mid][0] == target)
				return true;
			else if (matrix[mid][0]>target)
				high = mid - 1;
			else
				low = mid + 1;
		}
		low = (low + high) / 2;
		int start = 0, end = n - 1;
		while (start <= end)
		{
			int mid = (start + end) / 2;
			if (matrix[low][mid] == target)
				return true;
			else if (matrix[low][mid]>target)
				end = mid - 1;
			else
				start = mid + 1;
		}
		return false;
	}

};