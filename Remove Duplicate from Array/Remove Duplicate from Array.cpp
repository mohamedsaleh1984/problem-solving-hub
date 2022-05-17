// Remove Duplicate from Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void checkDupl(vector<int> input) {
	set<int> dup;
	for (int i = 0; i < input.size(); i++) {
		if (dup.count(input[i]) == 0)
		{
			dup.insert(input[i]);
			cout << input[i] << " ";
		}
	}
}

vector<int> removeDup(vector<int> arr) {
	if (arr.size() == 0) return {};
	if (arr.size() == 1) return arr;
	
	vector<int> vec;
	sort(arr.begin(), arr.end());
	vec.push_back(arr[0]);
	for (int i = 0, j = 1; j < arr.size(); ++i, ++j) {
		if (arr[i] != arr[j])
		{
			vec.push_back(arr[j]);
		}
	}
	return vec;
}

int main()
{
	vector<int> vec{ 1,10,20,1,6,8,15,33,8,8,10 };
	vector<int> res = removeDup(vec);
	
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	
	cout << "\n\n" << endl;

	checkDupl(vec);

}