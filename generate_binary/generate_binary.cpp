#include "../common.h"

class Solution
{
private:
	int N;

public:
	vector<string> generateBinaryUsingQueue(int N)
	{
		vector<string> result;
		queue<string> queue;

		queue.push("1");

		for (int i = 1; i <= N; i++)
		{
			string temp = queue.front();
			result.push_back(temp);

			queue.pop();
			queue.push(temp + "0");
			queue.push(temp + "1");
		}
		return result;
	}

	vector<string> generateBinaryUsingBitSets(int N)
	{
		vector<string> result;
		for (int i = 1; i <= N; i++)
		{
			bitset<8> num(i);
			result.push_back(num.to_string());
		}
		return result;
	}

	void printOut(vector<string> res)
	{
		for (auto x : res)
		{
			cout << x << endl;
		}
	}
};

int main()
{
	Solution S;
	vector<string> results = S.generateBinaryUsingBitSets(10);
	S.printOut(results);
	cout << "\n";
	results = S.generateBinaryUsingQueue(10);
	S.printOut(results);

	return 0;
}
