#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

class Solution76
{
public:

	//1.�����ظ��ĸ��ֿӰ����㲻���ˡ���
	//2.���˹��ˣ��ò����״������ظ��ģ���ʱ�ˡ�
	//�ҵ��뷨�Ǽ�¼��ÿ���ӽ�ȥ��λ�ã�Ȼ�����ظ�����ȥ�����Ǹ��ظ���
	//Ȼ�������漰�ܶ������ɾ�����������ֻ�Ƕ����˸�hash_map����¼��Щ���ظ��ģ�
	//Ȼ�������ǰ�߾ͺ��ˣ�ţ�ơ�
	string minWindow(string s, string t)
	{
		if (s.size() < t.size())
			return "";
		map<char, int> map_t;
		for (int i = 0; i < t.size(); i++)
			map_t[t[i]]++;
		vector<int> pos;
		int start = 0;
		int currlen = 0;
		int count = 0;
		int minLen = INT_MAX;
		char last;
		for (int i = 0; i < s.size(); i++)
		{
			if (map_t.find(s[i]) != map_t.end())
			{
				if (map_t[s[i]] != 0)
					map_t[s[i]]--;
				else if (last == s[i])
				{
					pos.back() = i;
					continue;
				}
				else
				{
					last = s[i];
					{
						for (vector<int>::iterator it = pos.begin(); it != pos.end();)
						if (s[*it] == s[i])
						{
							pos.erase(it);
							break;
						}
						else
							it++;
					}
					pos.push_back(i);
					continue;
				}

				pos.push_back(i);
				last = s[i];
				count++;
				if (count == t.size())
				{
					map_t[s[*pos.begin()]]++;
					count--;
					currlen = pos.back() - *pos.begin() + 1;
					if (currlen < minLen)
					{
						minLen = currlen;
						start = *pos.begin();
					}
					pos.erase(pos.begin());
				}
			}
		}
		string res;
		if (minLen == INT_MAX)
			return "";
		res += s.substr(start, minLen);
		return res;
	}

	private:
		int count1[256];
		int count2[256];
	public:

		
		string minWindow2(string S, string T) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			if (T.size() == 0 || S.size() == 0)
				return "";

			memset(count1, 0, sizeof(count1));
			memset(count2, 0, sizeof(count2));

			for (int i = 0; i < T.size(); i++)
			{
				count1[T[i]]++;
				count2[T[i]]++;
			}

			int count = T.size();

			int start = 0;
			int minSize = INT_MAX;
			int minStart;
			for (int end = 0; end < S.size(); end++)
			{
				if (count2[S[end]] > 0)
				{
					count1[S[end]]--;
					if (count1[S[end]] >= 0)//�ظ����ֵĲ����ȥ
						count--;
				}

				if (count == 0)
				{
					while (true)
					{
						if (count2[S[start]] > 0)
						{
							if (count1[S[start]] < 0)//�޳���ͷ���ظ���
								count1[S[start]]++;
							else
								break;
						}
						start++;
					}

					if (minSize > end - start + 1)
					{
						minSize = end - start + 1;
						minStart = start;
					}
				}
			}

			if (minSize == INT_MAX)
				return "";

			string ret(S, minStart, minSize);

			return ret;
		}
};