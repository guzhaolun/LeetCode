#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution187
{
public:
	//MLE���õġ�
	vector<string> findRepeatedDnaSequences(string s) 
	{
		unordered_map<string, int> m;
		vector<string> res;
		for (int i = 0; i < s.size()-9; i++)
		{
			string temp = s.substr(i, 10);
			m[temp]++;
			if (m[temp]==2)
				res.push_back(temp);
		}
		return res;
	}

	//http://blog.csdn.net/ljiabin/article/details/44488619
	//��Ȼ�ú���λ������ÿ��Ԫ�ء����߿�������λ��00,01,10,11
	vector<string> findRepeatedDnaSequences2(string s)
	{
		unordered_map<int, int> m;
		vector<string> res;
		int key = 0;
		for (int i = 0; i < s.size() ; i++)
		{
			key = ((key << 3) | (s[i] & 0x7)) & 0x3fffffff;
			if (i < 9)
				continue;
			m[key]++;
			if (m[key]==2)
				res.push_back(s.substr(i-9,10));
		}
		return res;
	}

	//��λ���������
	vector<string> findRepeatedDnaSequences3(string s) {
		unordered_map<int, int> m;
		vector<string> r;
		int t = 0, i = 0, ss = s.size();
		while (i < ss)
		if (m[t = (t << 3 | s[i++] & 7) & 0x3FFFFFFF]++ == 1)
			r.push_back(s.substr(i - 10, 10));
		return r;
	}
};