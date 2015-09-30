#include <vector>
#include <algorithm>
using namespace std;

class Solution221 
{
public:
	//���ÿһ���ۼ�
	int maximalSquare(vector<vector<char>>& matrix)
	{
		if (matrix.empty())
			return 0;
		int m = matrix.size(), n = matrix[0].size();
		vector<vector<int>> row(m, vector<int>(n,0));
		int maxv = 0;
		for (int i = 0; i < n; i++)
			row[0][i] = matrix[0][i] - '0';
		maxv = max(maxv, maximal(row[0]));
		for (int i = 1; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] != '0')
					row[i][j] = row[i - 1][j] + 1;
				else
					row[i][j] = 0;
			}
			//vector<int> t=row[i];
			maxv = max(maxv, maximal(row[i]));
		}
		return maxv;
	}

	//����ÿһ�У��ӵ�ǰ��չ��1��2,3�����о��ȽϷ�ʱ��
	int maximal(vector<int>& nums)
	{
		int n = nums.size();
		int maxv = 0;
		for (int i = 0; i < n; i++)
		{
			int h = nums[i];
			if (h == 0)
				continue;
			if (h == 1)
				maxv = max(maxv, h);
			else
			{
				int j = i + 1;
				int minh = nums[i];
				for (; j < n&&j<i+h; j++)
				{
					if (nums[j] < j - i + 1)
						break;
					minh = min(minh, nums[j]);
					if (minh < j - i + 1)
						break;
					maxv = max(maxv, (j - i + 1)*(j - i + 1));
				}
				
			}
		}
		return maxv;
	}

	//ֻ����ÿ�кϵ�һ��������ʵ�Ͱ�ԭʼ���ö�̬�滮����������ʱ����˽���һ������
	//���ƹ�ʽ���Ե�ǰ��(x,y) = '1' Ϊ���½ǵ���������εı߳�f(x,y) = min( f(x-1,y), f(x,y-1), f(x-1,y-1)) + 1.
	int maximalSquare2(vector<vector<char>>& matrix) {
		int m = matrix.size();
		if (m < 1)
		{
			return 0;
		}
		int n = matrix[0].size();
		if (n < 1)
		{
			return 0;
		}

		vector<vector<int> > size(m, vector<int>(n, 0));
		int maxSize = 0;
		for (int i = 0; i < m; i++)
		{
			if (matrix[i][0] == '1')
			{
				size[i][0] = 1;
				maxSize = 1;
			}
		}

		for (int i = 0; i < n; i++)
		{
			if (matrix[0][i] == '1')
			{
				size[0][i] = 1;
				maxSize = 1;
			}
		}

		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				//size[i][j] ��ʾ��matrix[i][j]Ϊ���½ǣ����γ�ȫΪ1�������εĳ��ȡ�  
				if (matrix[i][j] == '1')
				{
					size[i][j] = min(size[i - 1][j - 1],
						min(size[i - 1][j], size[i][j - 1])) + 1;
					maxSize = max(maxSize, size[i][j]);
				}
			}
		}

		return maxSize*maxSize;
	}
};