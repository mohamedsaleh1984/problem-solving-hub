#include "../common.h"
// https://leetcode.com/problems/longest-common-prefix/

class Solution
{
public:
    string longestCommonPrefix(vector<string> &s)
    {
        int ans = s[0].length();
        int n = s.size();

        for (int i = 1; i < n; i++)
        {
            // compare letters in each word comparing with 1+ words
            int j = 0;
            while (j < s[i].length() && s[i][j] == s[0][j])
                j++;
            ans = min(ans, j);
        }
        return s[0].substr(0, ans);
    }
};

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    Solution s;
    cout << s.longestCommonPrefix(strs) << endl;
    return 0;
}
