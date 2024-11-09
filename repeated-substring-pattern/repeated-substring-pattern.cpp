#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

struct TestCase
{
    string  input;
    bool    expectedOutput;
};

// https://leetcode.com/problems/repeated-substring-pattern/
// TODO
class Solution
{
public:
    /// @brief Check if two indecies in string are matching
    /// @param s  String of interest
    /// @param s1 first place
    /// @param s2 second place
    /// @param sublen length of the substring
    /// @return
    bool isMatching(string s, int s1, int s2, int sublen)
    {
        int cond = s1 + sublen;
        while (s1 < cond && s1 < s.length())
        {
            if (s[s1++] != s[s2++])
                return false;
        }
        return true;
    }

    bool repeatedSubstringPattern(string s)
    {
        int len = s.length();
        int times = 0;
        int sublen = -1;

        for (int i = 0; i < len; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                if (s[i] == s[j])
                {
                    sublen = (j - i) ;

        

                    // if (isMatching(s, i, j, sublen))
                    // {
                    //     string x = s.substr(j, s.length()-j);
                    //     repeatedSubstringPattern(x);
                    // }
                    // else
                    // {
                    //     return false;
                    // }
                }
            }
        }

        return true;
    }
};

void runTest(string strInput, bool expectedOutcome)
{
    Solution s;
    bool res = s.repeatedSubstringPattern(strInput);
    if (expectedOutcome == res)
        cout << "✅ Successful" << endl;
    else
        cout << "❌ Failed" << endl;
}

void runTestCases(vector<TestCase> ex)
{
    for (int i = 0; i < ex.size(); i++)
        runTest(ex.at(i).input,
                ex.at(i).expectedOutput);
}

int main(void)
{
    vector<TestCase> vec = {
        //{"ababba", false},
         {"abab", true},
        // {"aba", false},
        // {"abcabcabcabc", true}
        };

    runTestCases(vec);
    return 0;
}
