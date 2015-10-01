#include <vector>
using namespace std;
class Solution240
{
public:
	//对每一行做二分查找,O(mlgn),应该对m和n中大的那个做二分。
	bool searchMatrix(vector<vector<int>>& matrix, int target)
	{
		int m = matrix.size();
		if (m == 0)
			return false;
		int n = matrix[0].size();
		for (int i = 0; i < m; i++)
		{
			//可以做个预处理，大于行尾元素直接跳过这一行。
			if (target>matrix[i][n - 1])
				continue;
			if (search(matrix[i], target))
				return true;
		}
		return false;
	}

	bool search(vector<int>& nums, int target)
	{
		int left = 0, right = nums.size() - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (nums[mid] == target)
				return true;
			if (nums[mid] < target)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return false;
	}

	//微软面试题，从右上开始找，小了往左，大了往右,最坏O(m+n), 打败99.95%...
	bool searchMatrix2(vector<vector<int>>& matrix, int target)
	{
		int m = matrix.size();
		if (m == 0)
			return false;
		int n = matrix[0].size();
		int i = 0, j = n - 1;
		while (i < m && j >= 0)
		{
			if (matrix[i][j] == target)
				return true;
			else if (matrix[i][j] > target)
				j--;
			else
				i++;
		}
		return false;
	}
};