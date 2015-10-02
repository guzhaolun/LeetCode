#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution282
{
public:
	//打算先得到所有表达式然后再计算结果。发现获得表达式的过程都特别长，俺说都是递归列所有情况啊，第二个400ms能过。。。
	//第三个16ms,回头研究下怎么做的。。。。
	vector<string> addOperators(string num, int target)
	{
		vector<string> r;
		unordered_map<string,int> res = compute(num);
		for (unordered_map<string, int>::iterator j = res.begin(); j != res.end(); j++)
		{
		//	if (j->second == target)
		//		r.push_back(j->first);
			if (calculate(j->first) == target)
				r.push_back(j->first);
		}
		return r;
	}

	unordered_map<string, int> compute(string num)
	{
		unordered_map<string, int> result;
		if (num.empty())
			return result;
		for (int i = 1; i < num.size(); i++)
		{
			unordered_map<string, int> left = compute(num.substr(0, i));
			unordered_map<string, int> right = compute(num.substr(i, num.size()));
			
			for (unordered_map<string, int>::iterator j = left.begin(); j != left.end(); j++)
			{
				for (unordered_map<string, int>::iterator k = right.begin(); k != right.end(); k++)
				{
					for (int l = 0; l < 3; l++)
					{
						string res;
						int r=0;
						switch (l)
						{
						case 0:
							res=j->first +"*"+ k->first;
							r = j->second*k->second;//这边不能直接乘，比如2+3*2，直接乘的话就等于10了。。
							break;
						case 1:
							res = j->first + "-" + k->first;
							r = j->second-k->second;
							break;
						case 2:
							res = j->first + "+" + k->first;
							r = j->second+k->second;
							break;
						default:
							break;
						}
						result[res]=r;
					}
				}
			}
		}
	//	if (result.empty())
		result[num]=atoi(num.c_str());
		return result;
	}

	//计算表达式的结果
	int calculate(string s)
	{
		istringstream in(s + "+");
		long long total = 0, term, sign = 1, n;
		in >> term;
		char op;
		while (in >> op)
		{
			if (op == '+' || op == '-') 
			{
				total += sign * term;
				sign = 44 - op; //op == '+' ? 1 : -1
				in >> term;
			}
			else 
			{
				in >> n;
				if (op == '*')
					term *= n;
				else
					term /= n;
			}
		}
		return total;
	}
	/***************************************************************/
	vector<string> addOperators2(string num, int target)
	{
		vector<string> ret;
		if (num.length() == 0) return ret;
		help(num, target, ret, num[0] - '0', num.substr(0, 1), 1, 1);
		return ret;
	}

	void help(const string num, int target, vector<string> & v, long long last, string s, int idx, int left)
	{
		if (target == last*left && idx == num.length())
		{
			v.push_back(s);
			return;
		}
		else if (idx == num.length())
			return;
		else 
		{
			if (last != 0) 
				help(num, target, v, last * 10 + num[idx] - '0', s + num.substr(idx, 1), idx + 1, left);
			help(num, target, v, num[idx] - '0', s + '*' + num.substr(idx, 1), idx + 1, last*left);
			help(num, target - left*last, v, num[idx] - '0', s + '+' + num.substr(idx, 1), idx + 1, 1);
			help(num, target - left*last, v, num[idx] - '0', s + '-' + num.substr(idx, 1), idx + 1, -1);
		}
	}

private:
	typedef long long int i64;

	string myS;
	const char* s;
	i64 target;
	int slen;

public:
	//卧槽这个居然16ms..真牛逼
	vector<string> addOperators3(const string& num, int t) {
		myS = num;
		slen = myS.size();
		s = myS.c_str();
		target = t;

		vector<string> res;
		char* buf=new char[slen * 2 + 1];

		int lmax = (s[0] == '0' ? 1 : slen);
		i64 v = 0;
		for (int l = 1; l <= lmax; ++l) {
			int c = s[l - 1];
			v = v * 10 + (c - '0');   // add next digit
			buf[l - 1] = c;  // only need to append the last digit
			processTail(0, v, l, buf, l, res);
		}
		return res;
	}

	void processTail(i64 prevsum, i64 last, int pos, char* buf, int bufpos, vector<string>& res) {
		if (pos == slen) {
			// end of string
			// check the value and save
			if (prevsum + last == target) {
				buf[bufpos] = 0;
				res.push_back(buf);
			}
			return;
		}

		int lmax = (s[pos] == '0' ? 1 : slen - pos); // don't allow multichar intergers starting from a '0'
		i64 v = 0;
		for (int l = 1; l <= lmax; ++l) {
			int c = s[pos + l - 1];
			v = v * 10 + (c - '0');     // add next digit to v

			buf[bufpos] = '+';
			buf[bufpos + l] = c;      // only need to append the last digit of v
			processTail(prevsum + last, v, pos + l, buf, bufpos + l + 1, res);

			buf[bufpos] = '-';
			processTail(prevsum + last, -v, pos + l, buf, bufpos + l + 1, res);

			buf[bufpos] = '*';
			processTail(prevsum, last*v, pos + l, buf, bufpos + l + 1, res);
		}
	}
};