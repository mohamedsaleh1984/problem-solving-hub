// MoreseCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

class MorisNode
{
public:
	MorisNode(char d) {
		this->data = d;
		this->dash = nullptr;
		this->dot = nullptr;
	}

	char getData() {
		return this->data;
	}

	MorisNode* dot;
	MorisNode* dash;
private:
	char data = '*';
};

class MorisTree {
public:
	MorisTree(char input) {
		root = new MorisNode(input);
		root->dash = nullptr;
		root->dot = nullptr;

		BuildTree();
	}

	void BuildTree() {
		vector<tuple<string, char>> vec;
		vec.push_back({ "-",'T' });
		vec.push_back({ ".",'E' });
		vec.push_back({ "--",'M' });
		vec.push_back({ "-.",'N' });
		vec.push_back({ "---",'O' });
		vec.push_back({ "--.",'G' });
		vec.push_back({ "-.-",'K' });
		vec.push_back({ "-..",'D' });
		vec.push_back({ ".-",'A' });
		vec.push_back({ "..",'I' });
		vec.push_back({ ".--",'W' });
		vec.push_back({ ".-.",'R' });
		vec.push_back({ "..-",'U' });
		vec.push_back({ "...",'S' });

		for (int i = 0; i < vec.size(); i++) {
			tuple<string, char> tempObj = vec[i];
			insert(root, get<0>(tempObj), get<1>(tempObj));
		}
	}

	MorisNode* getRoot() {
		return this->root;
	}

	char Match(MorisNode* r, string input) {
		if (r->getData() != '*' && input.length() == 0) {
			return r->getData();
		}

		char c = input[0];
		string rest = "";

		if (input.length() > 1)
			rest = input.substr(1, input.length() - 1);
		else
			rest = "";

		if (c == '?') {
			return Match(r->dot, rest);
			return Match(r->dash, rest);
		}
		else if (c == '.')
			return Match(r->dot, rest);
		else if (c == '-')
			return Match(r->dash, rest);
	}

private:
	MorisNode* root;
	MorisNode* insert(MorisNode* r, string input, char data)
	{
		if (r == nullptr)
			return new MorisNode(data);

		char c = input[0];
		string rest = "";

		if (input.length() > 1)
			rest = input.substr(1, input.length() - 1);

		if (c == '.')
		{
			r->dot = insert(r->dot, rest, data);
		}
		else
		{
			r->dash = insert(r->dash, rest, data);
		}
		return r;
	}
};

void pvec(vector<char> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}

int main()
{
	MorisTree* cls = new MorisTree('*');
	/*pvec(cls->find("--."));
	pvec(cls->find("..."));
	pvec(cls->find(".-."));
	pvec(cls->find(".."));
	pvec(cls->find("-."));
	pvec(cls->find("-.?"));*/
	/*cout << cls->Match(cls->getRoot(), ".") << endl;
	cout << cls->Match(cls->getRoot(), "-") << endl;
	cout << cls->Match(cls->getRoot(), "-.") << endl;
	cout << cls->Match(cls->getRoot(), "...") << endl;
	cout << cls->Match(cls->getRoot(), "..-") << endl;*/
	//cout << cls->Match2(cls->getRoot(), "..") << endl;
	/*pvec(cls->find("?"));
	pvec(cls->find(".?"));
	pvec(cls->find(".?."));*/
	return 0;
}

