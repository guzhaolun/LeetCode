#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution166
{
public:
	//左三年右三年，缝缝补补又三年。
	//想的太少了，每次都是从测试用例中发现问题，然后一点点加代码，导致特别臃肿。。
	string fractionToDecimal(int numerator, int denominator)
	{
		int count = 0;
		int res = 0;
		string r;
		if (numerator == 0)
		{
			r += '0';
			return r;
		}
		if ((numerator < 0) ^ (denominator<0))
			r += '-';
		long long numerator1 = numerator;
		numerator1 = abs(numerator1);
		long long denominator1 = denominator; //一定要先变成long long 再取绝对值，否则还是负的
		denominator1 = abs(denominator1);
		//if (denominator == INT_MIN)
		//denominator1 = INT_MAX + 1; 还是 INT_MIN
		unordered_map<int, pair<int, int>> pos;
		int orign = 0;

		while (numerator1)
		{
			bool addDot = true;
			while (numerator1 < denominator1)
			{
				numerator1 *= 10;//这边会有INT*MAX*10的情况，所以usigned int 还是越界。
				count++;
				addDot = false;
			}
			unsigned int a = numerator1 / denominator1;
			unsigned int b = numerator1%denominator1;
			stringstream ss;
			string temp;
			if (count > 0)
			{
				if (r.empty() || (r.size() == 1 && r[0] == '-'))
				{
					if (count > 0)
					{
						r += '0';
						count--;
					}
					if (r.find_first_of('.') == -1)
					{
						r += '.';
					}
					while (count > 0)
					{
						r += '0';
						count--;
					}
				}
				else
				{
					count--;
					while (count > 0)
					{
						r += '0';
						count--;
					}

				}
			}

			if (pos.find(b) != pos.end() && pos[b].first == a)
			{
				int zero = r.size() - 1;
				int t = zero + 1;
				while (r[zero--] == '0')
					r = r.substr(0, r.size() - 1);

				int dot = pos[b].second - (t - r.size());
				r.insert(r.begin() + dot, '(');
				r.push_back(')');
				break;
			}
			else
			{
				ss << a;
				ss >> temp;
				ss.clear();
				r+=to_string(a);//居然直接有这个函数，孤陋寡闻了。
				r += temp;
				if (denominator1 == 1)
					return r;
				if (addDot&&b != 0)
					r += '.';
				numerator1 = b;
			}
			if (b == 0)
				break;
			orign = b;
			pos[orign] = make_pair(a, r.size() - 1);
		}
		return r;
	}

	//这是参考别人的修改版，先把整数的处理完再搞小数部分。
	string fractionToDecimal2(int numerator, int denominator) {
		string res = "";
		if (numerator == 0) return "0";
		if (denominator == 0)return res;

		long long n = numerator;
		long long d = denominator;
		if ((n < 0 ) ^ (d < 0))
			res = "-";
		if (n < 0) n = -n;
		if (d < 0) d = -d;
		res += to_string(n / d);
		n = n%d;
		if (n == 0) return res;
		res += '.';

		int pos = res.size();
		map<long long, int> record;
		while (n != 0) {
			if (record.find(n) != record.end()) {
				res.insert(res.begin() + record[n], '(');
				res += ')';
				return res;
			}
			record[n] = pos;
			res += char(n * 10 / d + '0');
			pos++;
			n = (n * 10) % d;
		}
		return res;
	}
};