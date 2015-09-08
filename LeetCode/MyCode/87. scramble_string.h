#include <string>
using namespace std;

class Solution87
{
public:
	/*�Ը���������ķ����ǴӼ򵥵�������˼�����Ӷ��ҳ����ɡ�
	* �ȿ���������
	* �ַ�������Ϊ1�������ԣ������ַ���������ȫ��ͬ�ſ��ԡ�
	* �ַ�������Ϊ2����s1 = "ab", s2ֻ��"ab"����"ba"�ſ��ԡ�
	* �������ⳤ�ȵ��ַ��������ǿ��԰��ַ���s1��Ϊa1, b1�������֣�s2��Ϊa2, b2�������֣����㣨(a1~a2) && (b1~b2)������ ��(a1~b2) && (a1~b2)��
	*/
	bool isScramble(string s1, string s2)
	{
		int l1 = s1.size(), l2 = s2.size();
		if (l1 != l2)
			return false;
		if (l1 == 1)
			return s1 == s2;
		//ͨ����������֦
		/*
		string t1 = s1, t2 = s2;
		sort(t1.begin(), t1.end());
		sort(t2.begin(), t2.end());
		for (int i = 0; i < l1; i++)
		if (t1[i] != t2[i])
			return false;
		*/
		//ͨ����������֦
		
		int A[26] = { 0 };
		for (int i = 0; i < s1.length(); i++)
			++A[s1[i] - 'a'];

		for (int j = 0; j < s2.length(); j++)
			--A[s2[j] - 'a'];

		for (int k = 0; k < 26; k++)
		if (A[k] != 0)
			return false;
		
		
		bool res = false;
		for (int i = 1; i < l1; i++)
		{
			string s11 = s1.substr(0, i);
			string s12 = s1.substr(i, l1 - i);
			string s21 = s2.substr(0, i);
			string s22 = s2.substr(i, l1 - i);
			res = isScramble(s11, s21) && isScramble(s12, s22);
			if (!res)
			{
				s21 = s2.substr(0, l1 - i);
				s22 = s2.substr(l1 - i, i);
				res = isScramble(s12, s21) && isScramble(s11, s22);
				if (res)
					return true;
			}
			else
				return true;
		}
		return res;
	}

	//��̬�滮����ά���飬dp[i][j][k]��ʾi,j��ʼ,k���ȵ��Ӵ��Ƿ�ƥ�䡣
	//����˼����ݹ����ͬ�������ж������������Ƿ��ܹ���ʾ��
	bool isScramble2(string s1, string s2)
	{
		int l1 = s1.size();
		int l2 = s2.size();
		if (l1 != l2)
			return false;
		vector<vector<vector<bool>>> dp(l1, vector<vector<bool>>(l1, vector<bool>(l1 + 1, false)));
		for (int i = l1 - 1; i >= 0; i--)
		{
			for (int j = l1 - 1; j >= 0; j--)
			{
				for (int k = 1; k <= l1-max(i,j); k++)
				{
					if (s1.substr(i, k) == s2.substr(j, k))
						dp[i][j][k] = true;
					for (int t = 1; t < k; t++)
					{
						if ((dp[i][j][t] && dp[i + t][j + t][k-t]) || (dp[i + t][j][k - t] && dp[i][j + k - t][t]))
						{
							dp[i][j][k] = true;
							break;
						}
					}
					
				}
			}
		}
		return dp[0][0][l1];
	}

};