#include <iostream>
#include <string>
#include <stack>
#include <vector>
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
		this->children = new TrieNode * [26];
		for (int i = 0; i < 26; i++) {
			this->children[i] = nullptr;
		}
	}

	vector<TrieNode*> getOccupiedNodes() {
		vector<TrieNode*> v;
		for (int i = 0; i < 26; i++) {
			if (this->children[i] != nullptr) {
				v.push_back(children[i]);
			}
		}
		return v;
	}

	bool IsThereNodes() {
		return this->getOccupiedNodes().size() > 0;
	}

	char data;
	TrieNode** children;
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

	bool startsWith(string prefix) {
		return getNode(prefix) != nullptr;
	}

	int numberOfWordsStartWith(string s) {
		TrieNode* cur = root;
		for (int i = 0; i < s.length(); i++) {
			char c = s[i];
			if (cur->children[c - 'a'] == nullptr)
				return 0;
			cur = cur->children[c - 'a'];
		}
		
		stack<TrieNode*> S;
		S.push(cur);

		vector<TrieNode*> vec;
		int counter = 0;

		while (!S.empty()) {
			TrieNode* poppedNode = S.top();
			if (poppedNode->isWord) {
				counter++;
			}
			S.pop();
			vec = poppedNode->getOccupiedNodes();
			for (int i = 0; i < vec.size(); i++) {
				S.push(vec[i]);
			}

		}
		return counter;
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

vector<int> contacts(vector<vector<string>> queries) {
	Trie* T = new Trie();
	vector<int> result;
	for (int i = 0; i < queries.size(); i++)
	{
		if (queries[i][0] == "add")
		{
			T->insert_word(queries[i][1]);
		}
		else
		{
			int num = T->numberOfWordsStartWith(queries[i][1]);
			cout << "finding " << queries[i][1] << " " << num << endl;
			result.push_back(num);
		}
	}
	return result;
}

int main()
{
	/*Trie* T = new Trie();
	T->insert_word("car");
	T->insert_word("cart");
	T->insert_word("cat");
	T->insert_word("cow");
	T->insert_word("cats");
	T->insert_word("mega");
	T->insert_word("mad");
	cout << T->numberOfWordsStartWith("c") << endl;
	*/
	/*vector< vector<string>> queries =
	{
		{"add","hack"},
		{"add","hackerrank"},
		{"find","hac"},
		{"find","hak"},
	};
	vector<int> queryResult = contacts(queries);
	for (int i = 0; i < queryResult.size(); i++) {
		cout << queryResult[i] << endl;
	}*/
	vector< vector<string>> queries =
	{
		{"add","s"},
		{"add","ss"},
		{"add","sss"},
		{"add","ssss"},
		{"add","sssss"},
		{"find","s"},
		{"find","ss"},
		/*{"find","sss"},
		{"find","ssss"},
		{"find","sssss"},*/
	};
	vector<int> queryResult = contacts(queries);
	/*for (int i = 0; i < queryResult.size(); i++) {
		cout << queryResult[i] << endl;
	}*/

	/*
	add s
	add ss
	add sss
	add ssss
	add sssss
	find s
	find ss
	find sss
	find ssss
	find sssss
	find ssssss
	

	5
	4
	3
	2
	1
	0
	*/


	return 0;
}
