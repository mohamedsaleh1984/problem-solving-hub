#include <iostream>
#include <stack>
#include <string>
using namespace std;

//https://leetcode.com/problems/backspace-string-compare
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Backspace String Compare.
*/
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string sTemp = "";
        string tTemp = "";

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '#' && sTemp.length() > 0) {
                sTemp.pop_back();
            }
            else if (s[i] == '#' && sTemp.length() == 0) {
                continue;
            }
            else
            {
                sTemp.push_back(s[i]);
            }
        }

        for (int i = 0; i < t.length(); i++)
        {
            if (t[i] == '#' && tTemp.length() > 0) {
                tTemp.pop_back();
            }
            else if (t[i] == '#' && tTemp.length() == 0) {
                continue;
            }
            else {
                tTemp.push_back(t[i]);
            }
        }

        return sTemp == tTemp;
    }
};

int main()
{
    Solution sol;
    string  s = "y#fo##f", t = "y#f#o##f";
    cout << sol.backspaceCompare(s, t) << endl;
}

 