#include <vector>
#include <algorithm>
using namespace std;
class Solution275
{
public:
	//À≥–Ú≤È’“
	int hIndex(vector<int>& citations)
	{
		//sort(citations.begin(), citations.end());
		int h = 0;
		int size = citations.size();
		for (int i = 0; i < citations.size(); i++)
		{
			if (size - i <= citations[i])
				return size - i;
		}
		return h;
	}

	int hIndex2(vector<int>& citations)
	{
		int size = citations.size();
		int left = 0, right = size - 1;
		int h = 0;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (citations[mid] >= size - mid)
			{
				h = max(h, size - mid);
				right = mid - 1;
			}
			else
				left = mid + 1;
		}
		return h;
	}

	int hIndex3(vector<int>& citations)
	{
		int size = citations.size();
		int left = 0, right = size - 1;
		int h = 0;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (citations[mid] == size - mid)
			{
				return mid + 1;
			}	
			else if (citations[mid] >size - mid)
				right = mid - 1;
			else
				left = mid + 1;
		}
		return size-left;
	}
};