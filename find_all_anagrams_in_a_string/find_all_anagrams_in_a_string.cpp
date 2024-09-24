#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stdbool.h>
using namespace std;

//https://leetcode.com/problems/find-all-anagrams-in-a-string/
//TODO: Fix TLE issue
class Solution {
private:
	map<char, int>::iterator it1;
	map<char, int>::iterator it2;
	vector<int> result = {};
	map<char, int> mapper;
	map<char, int> checker;
	int windowSize = 0;
	int iStart = 0;
public:
	Solution() {
		for (char c = 'a'; c <= 'z'; c++) {
			mapper[c] = 0;
			checker[c] = 0;
		}
	}

	bool checkMapsEquality(map<char, int> m1, map<char, int> m2) {
		it1 = m1.begin();
		it2 = m2.begin();

		if (m1.size() != m2.size())
			return false;

		while (it1 != m1.end() && it2 != m2.end()) {
			if (it1->first != it2->first || it1->second != it2->second) {
				return false;
			}
			it1++;
			it2++;
		}
		return true;
	}

    vector<int> findAnagrams(string s, string p) {
		if (s.length() < p.length())
			return {};

		for (int i = 0; i < p.length(); i++)
			mapper[p[i]]++;

		windowSize  = p.size();
		int iEnd = windowSize;
		int strSize = s.length();

		//load the first shot
		while (iStart < iEnd) {
			checker[s[iStart]]++;
			iStart++;
		}

		if (checkMapsEquality(mapper, checker))
			result.push_back(0);

		iStart = iEnd - windowSize;

		while (iEnd < strSize) {
			checker[s[iStart++]]--;
			checker[s[iEnd++]]++;

			if (checkMapsEquality(mapper, checker))
				result.push_back(iStart);
		}

		return result;
    }
};

int main()
{
    Solution sol;
	//string s = "cbaebabacd", p = "abc";
	string s = "abab", p = "ab";
	vector<int> res = sol.findAnagrams(s, p);
	for (auto x : res)
		cout << x << " ";
}
