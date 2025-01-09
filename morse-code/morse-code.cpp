#include "../common.h"

class MorseNode
{
public:
	MorseNode(char d)
	{
		this->data = d;
		this->dash = nullptr;
		this->dot = nullptr;
	}

	char getData()
	{
		return this->data;
	}

	MorseNode *dot;
	MorseNode *dash;

private:
	char data = '*';
};

class MorseTree
{
public:
	MorseTree(char input)
	{
		root = new MorseNode(input);
		root->dash = nullptr;
		root->dot = nullptr;

		BuildTree();
	}

	void BuildTree()
	{
		vector<tuple<string, char>> vec;
		vec.push_back({".-", 'A'});
		vec.push_back({"-...", 'B'});
		vec.push_back({"-.-.", 'C'});
		vec.push_back({"-..", 'D'});
		vec.push_back({".", 'E'});
		vec.push_back({"..-.", 'F'});
		vec.push_back({"--.", 'G'});
		vec.push_back({"....", 'H'});
		vec.push_back({"..", 'I'});
		vec.push_back({".---", 'J'});
		vec.push_back({"-.-", 'K'});
		vec.push_back({".-..", 'L'});
		vec.push_back({"--", 'M'});
		vec.push_back({"-.", 'N'});
		vec.push_back({"---", 'O'});
		vec.push_back({".-.", 'R'});
		vec.push_back({"...", 'S'});
		vec.push_back({"-", 'T'});
		vec.push_back({"..-", 'U'});
		vec.push_back({"...-", 'V'});
		vec.push_back({".--", 'W'});
		vec.push_back({"-..-", 'X'});
		vec.push_back({"-.--", 'Y'});
		vec.push_back({"--..", 'Z'});

		vec.push_back({".----", '1'});
		vec.push_back({"..---", '2'});
		vec.push_back({"...--", '3'});
		vec.push_back({"....-", '4'});
		vec.push_back({".....", '5'});
		vec.push_back({"-....", '6'});
		vec.push_back({"--...", '7'});
		vec.push_back({"---..", '8'});
		vec.push_back({"----.", '9'});
		vec.push_back({"-----", '0'});

		for (int i = 0; i < vec.size(); i++)
		{
			tuple<string, char> tempObj = vec[i];
			insert(root, get<0>(tempObj), get<1>(tempObj));
		}
	}

	MorseNode *getRoot()
	{
		return this->root;
	}

	char Match(MorseNode *r, string input)
	{
		if (r->getData() != '*' && input.length() == 0)
		{
			return r->getData();
		}

		char c = input[0];
		string rest = "";

		if (input.length() > 1)
			rest = input.substr(1, input.length() - 1);
		else
			rest = "";

		if (c == '?')
		{
			return Match(r->dot, rest);
			return Match(r->dash, rest);
		}
		else if (c == '.')
			return Match(r->dot, rest);
		else if (c == '-')
			return Match(r->dash, rest);
	}

private:
	MorseNode *root;
	MorseNode *insert(MorseNode *r, string input, char data)
	{
		if (r == nullptr)
			return new MorseNode(data);

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

void pvec(vector<char> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}

int main()
{
	MorseTree *cls = new MorseTree('*');

	cout << cls->Match(cls->getRoot(), ".") << endl;
	cout << cls->Match(cls->getRoot(), "-") << endl;
	cout << cls->Match(cls->getRoot(), "-.") << endl;
	cout << cls->Match(cls->getRoot(), "...") << endl;
	cout << cls->Match(cls->getRoot(), "..-") << endl;

	return 0;
}
