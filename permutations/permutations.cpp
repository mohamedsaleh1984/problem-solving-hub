#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
using namespace std;

class Solution {
private:
	vector<int> nums;
	vector<vector<int>> resultSet;
	vector<bool> used;
	vector<int> currentEntry;
public:
	Solution(vector<int> nums) {
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
	
	vector<int> nums{ 1,2,3,4 };
	Solution s(nums);
	vector<vector<int>> result = s.findPermutation();
	

	return 0;

}

class SolutionEx {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> vec;
		int n = nums.size();
		vector<int> arr(n);

		for (int i = 0; i < n; i++)
			arr[i] = nums[i];

		std::sort(arr.begin(), arr.end());

		do {
			vector<int> t;
			for (int i = 0; i < n; i++)
				t.push_back(arr[i]);
			vec.push_back(t);
		} while (std::next_permutation(arr.begin(), arr.end()));

		return vec;
	}
};