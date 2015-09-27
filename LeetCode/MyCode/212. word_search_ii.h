#include <vector>
#include <set>
using namespace std;

class TrieNode {
public:
	// Initialize your data structure here.
	TrieNode() {
		for (int i = 0; i < 26; i++)
			childs[i] = NULL;
		freq = 0;
	}
	char node;
	TrieNode* childs[26];
	int freq;//用来记录一个完整的单词。
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
		TrieNode* temp = root;
		for (int i = 0; i < word.size(); i++)
		{
			int id = word[i] - 'a';
			if (temp->childs[id] == NULL)
				temp->childs[id] = new TrieNode();
			temp->childs[id]->node = word[i];
			if (i == word.size() - 1)
				temp->childs[id]->freq++;
			temp = temp->childs[id];
		}
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		TrieNode* temp = root;
		int f = 0;
		for (int i = 0; i < word.size(); i++)
		{
			int id = word[i] - 'a';
			if (!temp->childs[id] )
				return false;
			f = temp->childs[id]->freq;
			temp = temp->childs[id];

		}
		return f>0;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		TrieNode* temp = root;
		for (int i = 0; i < prefix.size(); i++)
		{
			int id = prefix[i] - 'a';
			if (!temp->childs[id])
				return false;
			temp = temp->childs[id];
		}
		return true;
	}

private:
	TrieNode* root;
};

//直接dfs遍历超时了....
//但是用了trie树还是超时了，纳尼？
int Dir[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
class Solution212
{
	//DFS Find the path
public:

	void DFS(int curX, int curY, string str, vector<vector<bool>>& visit,
		vector<vector<char>> &board,  Trie& trie, vector<string>& res)
	{
		
		if (!trie.startsWith(str))
			return;
		if (trie.search(str))
			res.push_back(str);
		for (int d = 0; d < 4; ++d)
		{
			int nextX = curX + Dir[d][0];
			int nextY = curY + Dir[d][1];
			if (nextX >= 0 && nextX < board.size() && nextY >= 0 && nextY < board[0].size())
			{
				if (!visit[nextX][nextY])
				{
					visit[nextX][nextY] = true;
					DFS(nextX, nextY, str+board[nextX][nextY], visit, board,trie,res);
					visit[nextX][nextY] = false;
				}
			}

		}
	}
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> res;
		Trie trie;
		if (board.size() == 0 || board[0].size() == 0) return res;
		for (int i = 0; i < words.size(); i++)
		{
			trie.insert(words[i]);
		}
		vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));
		for (int i = 0; i < words.size(); i++)
		{
			for (int i = 0; i < board.size(); ++i)
			{
				for (int j = 0; j < board[i].size(); ++j)
				{
					visit[i][j] = true;
					string str;
					str += board[i][j];
					DFS(i, j, str, visit, board,trie,res);
					visit[i][j] = false;
				}
			}
		}
		return res;
	}
};

//但是用别人的就能过啊，看上去感觉没什么差别啊！！
//还有一种是在bfs的过程中进行trie的search，避免了每次在trie中从头开始搜索速度更快。
class Solution {
public:
	struct TriNode {
		TriNode *ch[26];
		bool isWord;
		TriNode() : isWord(false) {
			for (auto &a : ch) a = NULL;
		}
	} *root;

	void insert(string word) {
		TriNode *p = root;
		for (auto &a : word) {
			int i = a - 'a';
			if (p->ch[i] == NULL) p->ch[i] = new TriNode();
			p = p->ch[i];
		}
		p->isWord = true;
	}

	bool isPrefix(string word) {
		TriNode *p = root;
		for (auto &a : word) {
			int i = a - 'a';
			if (p->ch[i] == NULL) return false;
			p = p->ch[i];
		}
		return true;
	}

	bool isWord(string word) {
		TriNode *p = root;
		for (auto &a : word) {
			int i = a - 'a';
			if (p->ch[i] == NULL) return false;
			p = p->ch[i];
		}
		return p->isWord;
	}

	Solution() {
		root = new TriNode();
	}

	bool isValid(vector<vector<char>> &board, vector<vector<bool>> &visit, int x, int y) {
		int m = board.size(), n = board[0].size();
		if (x < 0 || x >= m || y < 0 || y >= n || visit[x][y]) return false;
		return true;
	}

	bool dfs(vector<vector<char>> &board, vector<vector<bool>> &visit, set<string> &st, string &s, int x, int y) {
		int dx[4] = { 1, 0, -1, 0 };
		int dy[4] = { 0, 1, 0, -1 };
		visit[x][y] = true;
		int xx, yy;
		for (int i = 0; i < 4; ++i) {
			xx = x + dx[i]; yy = y + dy[i];
			if (isValid(board, visit, xx, yy)) {
				s.push_back(board[xx][yy]);
				if (isWord(s)) st.insert(s);
				if (isPrefix(s)) dfs(board, visit, st, s, xx, yy);
				s.pop_back();
			}
		}
		visit[x][y] = false;
	}

	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> res;
		if (board.empty() || board[0].empty() || words.empty()) return res;
		for (auto &word : words) insert(word);
		int m = board.size(), n = board[0].size();
		vector<vector<bool>> visit(m, vector<bool>(n, false));
		string s;
		set<string> st;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				s.push_back(board[i][j]);
				if (isWord(s)) st.insert(s);
				if (isPrefix(s)) dfs(board, visit, st, s, i, j);
				s.pop_back();
			}
		}
		for (auto &word : st) res.push_back(word);
		return res;
	}
};