// Single Number - HashMap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

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
