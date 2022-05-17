#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//https://www.lintcode.com/problem/659/
/*
Description
Design an algorithm to encode a list of strings to a string.
The encoded string is then sent over the network and is decoded back to the original list of strings.

Please implement encode and decode
*/
class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string>& strs) {
        string result = "";
        for (int i = 0; i < strs.size(); i++) {
            result += strs[i] + "|";
        }
        return result;
    }

    /*
     * @param str: A string
     * @return: dcodes a single string to a list of strings
     */
    vector<string> decode(string& str) {
        vector<string> result;
        for (int i = 0; i < str.length(); i++) {
            string word = "";
            while (str[i] != '|') {
                word += str[i];
                i++;
            }
            result.push_back(word);
        }
        return result;
    }
};
int main()
{
    vector<string> vec = { "lint","code","love","you" };
    Solution s = Solution();
    string enc = s.encode(vec);
    cout << enc << endl;
    vector<string> decoded = s.decode(enc);
    for (auto i : decoded) {
        cout << i << endl;
    }
	return 0;
}
