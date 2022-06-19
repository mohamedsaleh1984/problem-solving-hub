#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;


class Permutations {
private:
	vector<int> nums;
	vector<vector<int>> resultSet;
	vector<bool> used;
	vector<int> currentEntry;
public:
	Permutations(vector<int> nums) {
		this->nums = nums;
		this->used.resize(nums.size(), false);
	}

	vector<vector<int>> findPermutation() {
		Solve();
		return resultSet;
	}
private:
	void Solve() {
		if (currentEntry.size() == nums.size()) {
			resultSet.push_back(currentEntry);
			return;
		}

		for (int i = 0; i < nums.size(); i++)
		{
			if (!used[i]) {

				used[i] = true;
				currentEntry.push_back(nums[i]);
				Solve();
				used[i] = false;
				currentEntry.pop_back();
			}
		}
	}
};

int main()
{ 

}