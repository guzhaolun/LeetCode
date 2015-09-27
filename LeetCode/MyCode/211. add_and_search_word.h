#include <string>
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

class WordDictionary 
{
private:
	TrieNode* root;
public:
	//一次过了，但是很慢，可能是因为一直取的substr，再传一个pos参数应该会好点。
	WordDictionary() {
		root = new TrieNode();
	}

	// Adds a word into the data structure.
	void addWord(string word)
	{
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

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) 
	{
		return search2(root, word,0);
	}

	bool search2(TrieNode* r, string word, int f1)
	{
		TrieNode* temp = r;
		if (word.empty()&&f1>0)
			return true;
		int f = 0;
		for (int i = 0; i < word.size(); i++)
		{
			if (word[0] != '.')
			{
				int id = word[0] - 'a';
				if (!temp->childs[id] || temp->childs[id]->node != word[0])
					return false;
				f = temp->childs[id]->freq;
				return search2(temp->childs[id], word.substr(1, word.size() - 1),f);
			}
			else
			{
				for (int j = 0; j<26; j++)
				{
					if (temp->childs[j] != NULL)
					{
						f = temp->childs[j]->freq;
						if (search2(temp->childs[j], word.substr(1, word.size() - 1), f))
							return true;
					}
				}
			}
		}
		return false;
	}
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");


//这份代码就比我的快五倍。。主要不同就是searchWord的参数。
class WordDictionary2 {
public:
	struct TrieNode {
	public:
		TrieNode *child[26];
		bool isWord;
		TrieNode() : isWord(false) {
			for (auto &a : child) a = NULL;
		}
	};

	WordDictionary2() {
		root = new TrieNode();
	}

	// Adds a word into the data structure.
	void addWord(string word) {
		TrieNode *p = root;
		for (auto &a : word) {
			int i = a - 'a';
			if (!p->child[i]) p->child[i] = new TrieNode();
			p = p->child[i];
		}
		p->isWord = true;
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {
		return searchWord(word, root, 0);
	}

	bool searchWord(string &word, TrieNode *p, int i) {
		if (i == word.size()) return p->isWord;
		if (word[i] == '.') {
			for (auto &a : p->child) {
				if (a && searchWord(word, a, i + 1)) return true;
			}
			return false;
		}
		else {
			return p->child[word[i] - 'a'] && searchWord(word, p->child[word[i] - 'a'], i + 1);
		}
	}

private:
	TrieNode *root;
};