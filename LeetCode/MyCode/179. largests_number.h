#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

class Solution179
{
public:

	//�뷨���ȱ��һ�����ģ�Ȼ�����򣬴Ӵ�С�Ӿͺ��ˡ������Ժ��ֲ��ԣ�����12,121��12,124��
	string largestNumber(vector<int>& nums)
	{
		int maxv = *max_element(nums.begin(), nums.end());
		int len = getLen(maxv);
		string res;
		map<int,vector<int>> changed;
		sort(nums.begin(), nums.end());
		//�ȱ����ͬ�ĳ��ȣ�����һ��map�У������Ѿ����ڵľ��ں�����루��Ϊԭ�����Ѿ����򣩡�
		for (int i = 0; i < nums.size(); i++)
		{
			changed[change(nums[i], len)].push_back( nums[i]);
		}
		//�������map�ͺá�
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

	//���־��Ǹ��������⣬ֻ�ǱȽϴ�С�Ĺ�����ˣ���дһ��compare�����ͺ��ˡ�
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

	bool static cmp(const int& a,const int& b)//cmp������Ϊ���Աֻ����static���ͣ���Ȼ��ǰ��֪������
	{
		//0��Ҫ���⴦��һ�£�����0��9��
		long long n1 = a==0?b:a*pow(10, getLen(b)) + b;//int Խ���ˡ�
		long long n2 = b==0?a:b*pow(10, getLen(a)) + a;
		return n1 > n2;
	}
};