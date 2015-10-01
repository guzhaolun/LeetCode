#include <vector>
using namespace std;
class Solution240
{
public:
	//��ÿһ�������ֲ���,O(mlgn),Ӧ�ö�m��n�д���Ǹ������֡�
	bool searchMatrix(vector<vector<int>>& matrix, int target)
	{
		int m = matrix.size();
		if (m == 0)
			return false;
		int n = matrix[0].size();
		for (int i = 0; i < m; i++)
		{
			//��������Ԥ����������βԪ��ֱ��������һ�С�
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

	//΢�������⣬�����Ͽ�ʼ�ң�С�����󣬴�������,�O(m+n), ���99.95%...
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