#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;
/*
https://leetcode.com/problems/sort-array-by-increasing-frequency/
*/

vector<int> frequencySort(vector<int>& nums) {
	map<int, int> zmap;
	for (int i = 0; i < nums.size(); i++) {
		zmap[nums[i]]++;
	}
	set<int> duplicateFinder;
	bool desc = false;
	map<int, int>::iterator itr = zmap.begin();
	while (itr != zmap.end()) {

		if (!duplicateFinder.count(itr->second))
			duplicateFinder.insert(itr->second);
		else {
			desc = true;
			break;
		}
		itr++;
	}

	priority_queue<pair<int, int>> ranker;
	itr = zmap.begin();
	while (itr != zmap.end()) {
		ranker.push(make_pair(itr->second, itr->first));
		itr++;
	}

	vector<int> result;
	if (!desc) {
		stack<pair<int, int>> stk;
		while (!ranker.empty()) {
			stk.push(ranker.top());
			ranker.pop();
		}
		vector<int> result;
		while (!stk.empty()) {
			pair<int, int> temp = stk.top();
			for (int i = 0; i < temp.first; i++) {
				result.push_back(temp.second);
			}
			stk.pop();
		}
		return result;
	}
	else {
		while (!ranker.empty()) {
			pair<int, int> temp = ranker.top();
			for (int i = 0; i < temp.first; i++) {
				result.push_back(temp.second);
			}
			ranker.pop();
		}
	}

	return result;
}


int main()
{
	vector<int> dd = { 1,1,1,2,2,2,3 };
	vector<int> sss = frequencySort(dd);
	for (auto f : sss) {
		cout << f << " ";
	}
	return 0;
}
