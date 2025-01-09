#include "../common.h"

/*
https://leetcode.com/problems/sort-characters-by-frequency/
*/

string frequencySort(string s) {
    unordered_map<char, int> freqTable;
    priority_queue<pair<int, char>> ranker;

    for (int i = 0; i < s.length(); i++) {
        freqTable[s[i]]++;
    }

    unordered_map<char, int>::iterator iter = freqTable.begin();

    while (iter != freqTable.end()) {
        ranker.push(make_pair(iter->second, iter->first));
        iter++;
    }

    string strToReturn;
    while (!ranker.empty()) {
        pair<int, char> elem = ranker.top();
        ranker.pop();
        vector<char> tempStr(elem.first);
        fill(tempStr.begin(), tempStr.end(), elem.second);
        string sTemp(tempStr.begin(), tempStr.end());
        strToReturn += sTemp;
    }
    return strToReturn;
}

int main()
{
    string s = "tree";
    cout << frequencySort(s) << endl;

	return 0;
}
