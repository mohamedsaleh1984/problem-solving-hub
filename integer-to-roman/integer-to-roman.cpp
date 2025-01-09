#include "../common.h"

// https://leetcode.com/problems/integer-to-roman/?envType=problem-list-v2&envId=math
class Solution
{
public:
    string repeatChars(char c, int n)
    {
        string s = "";
        while (n--)
            s += c;
        return s;
    }

    string intToRoman(int num)
    {
        string strOutput = "";
        int c = 0;
        while (num > 0)
        {
            if (num >= 1000)
            {
                c = num / 1000;
                num = num - (1000 * c);
                strOutput += repeatChars('M', c);
            }
            else if (num >= 500)
            {
                c = num / 500;
                num = num - (500 * c);
                strOutput += repeatChars('D', c);
            }
            else if (num >= 100)
            {
                c = num / 100;
                num = num - (100 * c);
                strOutput += repeatChars('C', c);
            }
            else if (num >= 50)
            {
                c = num / 50;
                num = num - (50 * c);
                strOutput += repeatChars('L', c);
            }
            else if (num >= 10)
            {
                c = num / 10;
                num = num - (10 * c);
                strOutput += repeatChars('X', c);
            }
            else if (num >= 5)
            {
                c = num / 5;
                num = num - (5 * c);
                strOutput += repeatChars('V', c);
            }
            else
            {
                strOutput += repeatChars('I', num);
                num = 0;
            }
        }

        return strOutput;
    }
};

struct TestCase
{
    int num;
    string expectedOutput;

    TestCase(
        int num,
        string expectedOutput)
    {
        this->num = num;
        this->expectedOutput = expectedOutput;
    }
};

void runTest(int num, string expectedOutcome)
{
    Solution s;
    string outcome = s.intToRoman(num);

    if (expectedOutcome == outcome)
        cout << "✅ Successful" << endl;
    else
    {
        cout << "❌ Failed" << endl;
        cout << "Expected output " << expectedOutcome << ", your output is " << outcome << endl;
    }
}

void runTestCases(vector<TestCase> ex)
{
    for (int i = 0; i < ex.size(); i++)
    {
        runTest(ex.at(i).num, ex.at(i).expectedOutput);
    }
}

int main(void)
{
    vector<TestCase> vec = {
        {3749, "MMMDCCXLIX"}
        //,{58,"LVIII"},{1994,"MCMXCIV"}
    };
    runTestCases(vec);

    return 0;
}