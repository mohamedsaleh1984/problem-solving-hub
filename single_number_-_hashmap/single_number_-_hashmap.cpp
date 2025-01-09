#include "../common.h"

int singleNumber(vector<int>& nums) {

	unordered_set<int> hashset;
	int one = 0;
	for (int key : nums) {
		if (hashset.count(key) > 0) {
			hashset.erase(key);
		}
		else {
			hashset.insert(key);
		}
	}

	if (hashset.size() == 1) {
		unordered_set<int>::iterator it = hashset.begin();
		one = *it;
	}
	return one;
}

int main()
{
	vector<int> nums = { 2,2,1 };
	cout << singleNumber(nums) << endl;


	return 0;
}
