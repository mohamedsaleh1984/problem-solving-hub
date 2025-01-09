#include "../common.h"

//384. Shuffle an Array
//https://leetcode.com/problems/shuffle-an-array/
class Solution {
private:
	vector<int> copy = {};
	vector<int> vecToReturn = {} ;
	int size = 0;
	unsigned int seed = 0;
public:

	Solution(vector<int>& nums) {
		copy.assign(nums.begin(), nums.end());
		size = nums.size();
		srand(time(NULL));
	}

	vector<int> reset() {
		return copy;
	}

	vector<int> generateList(int N) {
		unordered_set<int> myResult;
		
		while (myResult.size() != N) {
			int temp = rand() % N;
			myResult.insert(temp);
		}
		vector<int> vecResult(myResult.begin(), myResult.end());
		return vecResult;
	}

	vector<int> shuffle() {
		vector<int> result(this->size);
		vector<int> randomList = generateList(this->size);

		for (int i = 0; i < this->size; i++)
			result[i] = copy[randomList[i]];

		return result;
	}
};



void print(vector<int> c) {
	for (auto a : c)
		cout << a << " ";
	cout << endl;
}

int main()
{
	vector<int> nums = { -6,10,184 };
	Solution s(nums);

	for (int i = 0; i < 5; i++) {
		vector<int> results = s.shuffle();
		print(results);
	}
	return 0;
	
}