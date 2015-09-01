#include <string>
#include <stack>

using namespace std;

class Solution71
{
public:
	string simplifyPath(string path)
	{
		stack<string> res;
		string temp;
		string result;
		int len = path.size();
		for (int i = 0; i < len;)
		{

			while (i < len&&path[i] == '/')
				i++;
			while (i < len&&path[i] != '/')
				temp += path[i++];
			if (temp == ".."&& !res.empty())
				res.pop();
			else if (temp != ""&&temp != "."&&temp!="..")
				res.push(temp);
			temp.clear();
		}

		while (!res.empty())
		{
			result = "/" + res.top() + result;
			res.pop();
		}
		if (result.empty())
			result += '/';
		return result;
	}
};