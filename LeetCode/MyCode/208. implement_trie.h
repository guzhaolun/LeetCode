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
			if (!temp->childs[id] || temp->childs[id]->node != word[i])
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
			if (!temp->childs[id]||temp->childs[id]->node != prefix[i])
				return false;
			temp = temp->childs[id];
		}
		return true;
	}

private:
	TrieNode* root;
};
// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
