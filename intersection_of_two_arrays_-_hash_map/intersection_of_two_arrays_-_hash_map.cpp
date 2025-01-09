#include "../common.h"

vector<int> distinct(vector<int> vec) {
	unordered_set<int> set;
	for (int elem : vec) {
		if (set.count(elem) == 0)
			set.insert(elem);
	}
	vector<int> distinctVals(set.begin(), set.end());
	return distinctVals;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	vector<int> a = distinct(nums1);
	vector<int> b = distinct(nums2);
	unordered_set<int> set;
	vector<int> res; 
	for (int elem : a) {
		set.insert(elem);
	}
	for (int elem : b) {
		if (set.count(elem) != 0)
			res.push_back(elem);
	}
	return res;
}

int main()
{
	vector<int> arr1 = { 4,9,5 };
	vector<int> arr2 = { 9,4,9,8,4 };

	vector<int> res = intersection(arr1, arr2);
	for (int elem : res) {
		cout << elem << " ";
	}
	
	return 0;
}