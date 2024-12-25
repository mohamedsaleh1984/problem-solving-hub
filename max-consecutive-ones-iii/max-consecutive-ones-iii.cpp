#include "../common.h"

// https://leetcode.com/problems/max-consecutive-ones-iii/?envType=study-plan-v2&envId=leetcode-75
// FIX_IT

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        return 0;
    }
};

int main()
{

    vector<vector<int>> testCasesNums = { {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0},
                                          {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1}};
    vector<int> testCasesKs = {2, 3};

    Solution s;

    for (int i = 0; i < testCasesKs.size(); i++)
    {
        cout << s.longestOnes(testCasesNums[i], testCasesKs[i]) << endl;
    }

    return 0;
}
