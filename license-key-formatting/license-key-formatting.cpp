
#include <iostream>
#include <string>
#include <algorithm> // std::reverse
#include <vector>    // std::vector
using namespace std;

struct TestCase
{
    string input;
    int k;
    string expectedOutput;
};

// https://leetcode.com/problems/license-key-formatting/
// 2msBeats 60.99%

class Solution
{
public:
    int numberOfCharacters(string s)
    {
        int acceptableChars = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != '-')
                acceptableChars++;
        }
        return acceptableChars;
    }

    int getGroups(string s, int k)
    {
        int acceptableChars = numberOfCharacters(s);
        return (acceptableChars / k) + (acceptableChars % k > 0 ? 1 : 0);
    }

    string licenseKeyFormatting(string s, int k)
    {
        string strNew, chunk = "";
        int groups = getGroups(s, k);
        int charLength = numberOfCharacters(s);
        int firstGrpElmCount = charLength > k ? charLength % k : charLength;
        int groupIndex = 1;

        for (int i = 0; i < s.length(); i++)
        {
            // skip the - character
            if (s[i] == '-')
                continue;

            // push the char to the chunk builder
            chunk.push_back(toupper(s[i]));
            if (groupIndex == 1 && chunk.length() == firstGrpElmCount)
            {
                 if (groupIndex != groups)
                    chunk.push_back('-');

                groupIndex++;
                strNew += chunk;
                chunk = "";
            }

            if (chunk.length() == k)
            {
                if (groupIndex != groups)
                    chunk.push_back('-');
                strNew += chunk;
                chunk = "";
                 groupIndex++;
            }
        }
        return strNew;
    }
};

void runTest(string strInput, int k, string expectedOutcome)
{
    Solution s;
    string res = s.licenseKeyFormatting(strInput, k);
    if (expectedOutcome == res)
        cout << "✅ Successful" << endl;
    else
    {
        cout << "❌ Failed" << endl;
        cout << "\tYour output is (" << res << ") and expected output is (" << expectedOutcome << ")" << endl;
    }
}

void runTestCases(vector<TestCase> ex)
{
    for (int i = 0; i < ex.size(); i++)
        runTest(ex.at(i).input,
                ex.at(i).k,
                ex.at(i).expectedOutput);
}

int main(void)
{
    vector<TestCase> vec = {
        // {"2-4A0r7-4k", 3, "24-A0R-74K"},
        // {"5F3Z-2e-9-w", 4, "5F3Z-2E9W"},
        // {"2-5g-3-J", 2, "2-5G-3J"},
        // {"r", 1, "R"},
        // {"2", 2, "2"},
        // {"a-a-a-a-",1,"A-A-A-A"},
        {"a-----a",2,"AA"}};
    runTestCases(vec);
    return 0;
}