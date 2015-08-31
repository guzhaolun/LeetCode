#include <vector>
using namespace std;

class Solution68
{
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth)
	{
		if (words.empty())
			return words;

		vector<string> res;
		if (words[0].empty())
			res.push_back("");
		string temp;
		for (int i = 0; i < words.size();)
		{
			if (words[i] == "")
				break;
			if (temp.size() != 0 && temp.size() + 1<maxWidth)
				temp += ' ';
			while (i<words.size() && temp.size() + words[i].size() <= maxWidth)
			{
				temp += words[i];
				i++;
				if (temp.size() + 1 < maxWidth)
					temp += ' ';
				else
					break;
			}
			if (i == words.size())
			{
				res.push_back(temp);
				break;
			}
			//i--;
			//else
			{
				if (temp.back() == ' ')
					temp.erase(temp.end() - 1);
				int space = maxWidth - temp.length();
				bool add = false;
				while (space > 0)
				{
					for (int j = 0; space>0 && j < temp.size(); j++)
					{
						if (temp[j] == ' ')
						{

							temp.insert(temp.begin() + j, ' ');
							space--;
							add = true;
							while (temp[j] == ' ')j++;
						}
					}
					if (!add)
					{
						for (int i = temp.size(); i < maxWidth; i++)
							temp += ' ';
						break;
					}
				}
				res.push_back(temp);
				temp.clear();
			}
		}
		int lastIndex = res.size() - 1;
		//if (lastIndex < 0)
		//	return res;
		for (int i = 0; lastIndex >= 0 && i < res[lastIndex].size(); i++)
		{
			while (res[lastIndex][i] == ' '&&res[lastIndex][i + 1] == ' ')
				res[lastIndex].erase(res[lastIndex].begin() + i);
		}
		for (int i = res[lastIndex].size(); i < maxWidth; i++)
			res[lastIndex] += ' ';
		return res;
	}
};