#include <vector>
using namespace std;

class Solution119
{
public:
	vector<int> getRows(int rowIndex)
	{
		rowIndex++;
		vector<int> row(rowIndex,0);
		if (rowIndex== 0)
			return row;
		row[0]=1;
		if (rowIndex == 1)
			return row;
		for (int i = 2; i <= rowIndex; i++)
		{
			row[0] = 1;
			row[i - 1] = 1;
			int temp = 0,last=1;
			for (int j = 1; j < i-1; j++)
			{
				temp = row[j];
				row[j] = last + row[j];
				last = temp;
			}
		}
		return row;
	}
};