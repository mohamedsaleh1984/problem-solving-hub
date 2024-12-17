#include "../common.h"
// https://leetcode.com/problems/can-place-flowers/
// FIX_IT
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        // flowerbed size
        int fbs = flowerbed.size();

        return n == 0 ? true : false;
    }
};

int main()
{
    vector<int> vec = {1, 0, 0, 0, 1, 0, 0};
    vector<int> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0};
    vector<vector<int>> TestCases = {
        {0, 0, 1, 0, 1},
    };
    vector<int> TestCaseOutput = {1};

    int n = 1;

    vector<int> vec2 = {0, 1, 0};
    Solution s;
    cout << (s.canPlaceFlowers(vec2, n) ? "Yes" : "No") << endl;
    cout << endl;
    printvector(vec);

    return 0;

    //eros manos
}