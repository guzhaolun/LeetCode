#include <vector>
#include <algorithm>
using namespace std;
class Solution274
{
public:
	//ֱ������
	int hIndex(vector<int>& citations)
	{
		sort(citations.begin(), citations.end());
		int h = 0;
		int size = citations.size();
		for (int i = 0; i < citations.size(); i++)
		{
			if (size - i <= citations[i])
				return size - i;
		}
		return h;
	}

	//���ö���ռ䣬O(n)
	int hIndex2(vector<int>& citations)
	{
		int maxp = citations.size(), ret = 0;
		vector<int> freq(maxp + 1);
		for (auto i : citations) 
			freq[min(maxp, i)]++;
		for (int i = 0; i < maxp + 1; i++)
		{
			if (maxp >= i) ret = i;
			maxp -= freq[i];//��ȥС��
		}
		return ret;
	}
};