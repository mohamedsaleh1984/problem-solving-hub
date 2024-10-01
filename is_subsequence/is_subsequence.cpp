#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/is-subsequence/

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int grid[s.size()][t.size()];
        for (int x = 0; x < s.size() * t.size(); x++)
            *((int *)grid + x) = 0;

        int prev = 0;
        int j = 0;
        int i = 0;

        while (s[0] != t[j])
            j++;

        for (int i = 0; i < s.size(); i++)
        {
            for (; j < t.size(); j++)
            {
                if (s[i] == t[j])
                {
                    grid[i][j] = prev + 1;
                    prev = grid[i][j];
                }
                else
                {
                    grid[i][j] = 0;
                }
            }
        }

        return s.size() == grid[s.size() - 1][t.size() - 1];
    }
};
int main()
{
    string s = "aaaaaa", t = "bbaaaa";
    Solution sol = Solution();
    cout << sol.isSubsequence(s, t) << endl;
}
