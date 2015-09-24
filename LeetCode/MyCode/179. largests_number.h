#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

class Solution179
{
public:

	//想法是先变成一样长的，然后排序，从大到小加就好了。测试以后发现不对，比如12,121和12,124。
	string largestNumber(vector<int>& nums)
	{
		int maxv = *max_element(nums.begin(), nums.end());
		int len = getLen(maxv);
		string res;
		map<int,vector<int>> changed;
		sort(nums.begin(), nums.end());
		//先变成相同的长度，存入一个map中，遇到已经存在的就在后面加入（因为原数组已经有序）。
		for (int i = 0; i < nums.size(); i++)
		{
			changed[change(nums[i], len)].push_back( nums[i]);
		}
		//反向遍历map就好。
		for (map<int, vector<int>>::reverse_iterator it = changed.rbegin(); it != changed.rend(); it++)
		{
			for (int i = 0; i < it->second.size();i++)
			res += to_string(it->second[i]);
		}
		return res;
	}

	int change(int num, int len)
	{
		int l = getLen(num);
		return num*pow(10,(len - l));
	}

	int static getLen(int num)
	{
		if (num == 0)
			return 1;
		int l = 0;
		while (num)
		{
			num /= 10;
			l++;
		}
		return l;
	}

	//发现就是个排序问题，只是比较大小的规则变了，重写一下compare函数就好了。
	string largestNumber2(vector<int>& nums)
	{
		string res;
		//sort(nums.begin(), nums.end());
		sort(nums.begin(), nums.end(), cmp);
		for (int i = 0; i < nums.size(); i++)
		{
			res += to_string(nums[i]);
		}
		if (!res.empty() && res[0] == '0')
			res = "0";
		return res;
	}

	bool static cmp(const int& a,const int& b)//cmp函数作为类成员只能是static类型，居然以前不知道。。
	{
		//0需要特殊处理一下，否则0比9大。
		long long n1 = a==0?b:a*pow(10, getLen(b)) + b;//int 越界了。
		long long n2 = b==0?a:b*pow(10, getLen(a)) + a;
		return n1 > n2;
	}
};