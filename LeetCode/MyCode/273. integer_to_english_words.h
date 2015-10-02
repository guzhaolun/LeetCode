#include <string>
#include <vector>

using namespace std;
class Solution273
{
private:

public:
	string numberToWords(int num) {
		vector<string> strarr = { "Thousand", "Million", "Billion" };
		string res;
		if (num == 0)
			return "Zero";
		res = smallThan1000(num % 1000);
		bool has = false;
		if (!res.empty())
			has = true;
		int pos = 0;
		while (num / 1000 > 0)
		{
			num /= 1000;
			res = num % 1000 ? smallThan1000(num % 1000) + " " + strarr[pos] + " " + res : res;
			pos++;
		}
		while (res.back() == ' ')res.pop_back();
		return res;
	}

	string smallThan1000(int num)
	{
		vector<string> arr1 = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
			"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
		vector<string> arr2 = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
		string res;
		int a = num / 100;
		res += arr1[a];
		if (a != 0)
		{
			res += " ";
			res += "Hundred";

		}
		int b = num % 100;
		if (a != 0 && b != 0)
			res += " ";
		if (b < 20)
		{
			res += arr1[b];
		}
		else
		{
			int c = b % 10;
			b = b / 10;
			res += arr2[b];
			if (c != 0)
				res += " ";
			res += arr1[c];
		}
		return res;
	}
};