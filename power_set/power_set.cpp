#include <iostream>
#include <vector>
#include <map>
using namespace std;

class PowerSet {
	vector<vector<int>> powerset;
	vector<int> nums;
public:
	PowerSet(vector<int> ns) {
		this->nums = ns;
	}
	// Function to print a given set
	void printSet(vector<int> const& input)
	{
		cout << "[";
		int n = input.size();
		for (int i : input) {
			cout << i;
			if (--n) {
				cout << ", ";
			}
		}
		cout << "]\n";
	}


	// Function to generate power set of a given set `S`
	void printPowerSet(vector<int> const& S, vector<int>& set, int n)
	{
		// if we have considered all elements
		if (n == 0)
		{
			printSet(set);
			return;
		}

		// consider the n'th element
		set.push_back(S[n - 1]);
		printPowerSet(S, set, n - 1);

		set.pop_back();                    // backtrack

		// or don't consider the n'th element
		printPowerSet(S, set, n - 1);
	}

	void findPowerSet() {
		printPowerSet(nums, nums, nums.size());
	}
};

int main()
{
    
}
