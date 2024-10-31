#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/is-subsequence/
// 0ms 100.00%


class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int p1 = 0;
        int p2 = 0;

        while(p2 < t.size()){
            if(s[p1] == t[p2]){
                p1++;
                p2++;
            }
            else{
                p2++;
            }
        }

        return p1 == s.size() && p2 == t.size();
    }
};
int main()
{
    string s = "aaaaaa", t = "bbaaaa";
    Solution sol = Solution();
    cout << sol.isSubsequence(s, t) << endl;
}
