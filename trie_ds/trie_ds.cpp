#include <iostream>
#include <string>
using namespace std;
#define SIZE 26


class TrieNode {
public:
	TrieNode() {
		this->data = '\0';
		this->isWord = false;
		this->children = new TrieNode * [26];
		for (int i = 0; i < 26; i++) {
			this->children[i] = nullptr;
		}
	}
	TrieNode(char c) {
		this->data = c;
		this->isWord = false;
		this->children = new TrieNode*[26];
		for (int i = 0; i < 26; i++) {
			this->children[i] = nullptr;
		}
	}

	char data;
	TrieNode** children ;
	bool isWord;
};

class Trie {
public:
	Trie() {
		root = new TrieNode('\0');
	}

	void insert_word(string str) {
		TrieNode* cur = root;
		for (size_t i = 0; i < str.length(); i++)
		{
			char c = str[i];
			
			if (cur->children[c - 'a'] == nullptr)
				cur->children[c - 'a'] = new TrieNode(c);

			cur = cur->children[c - 'a'];
		}
		cur->isWord = true;
	}

	bool Search(string word) {
		TrieNode* node = getNode(word);
		if (node == nullptr)
			return false;
		return node->isWord == true;
	}
private:
	TrieNode* root;
	TrieNode* getNode(string str) {
		TrieNode* cur = root;
		for (size_t i = 0; i < str.length(); i++)
		{
			char c = str[i];
			if (cur->children[c - 'a'] == NULL)
				return nullptr;
			cur = cur->children[c - 'a'];
		}
		return cur;
	}
};

int main()
{
	Trie* T = new Trie();
	T->insert_word("mega");
	T->insert_word("mody");
	T->insert_word("maddy");


	cout << T->Search("mody") << endl;

	cout << T->Search("maaada") << endl;

	return 0;
}