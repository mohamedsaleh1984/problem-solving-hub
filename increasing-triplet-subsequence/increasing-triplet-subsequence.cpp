#include "../common.h"
// https://leetcode.com/problems/increasing-triplet-subsequence
//
class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        if (nums.size() < 3)
            return false;

        bool result = false;

        int i = 0, j = 1, k = nums.size() - 1;

        while (i < j && j < k)
        {
            int vi = nums[i];
            int vj = nums[j];
            int vk = nums[k];

            // Bingo
            if (vi < vj && vj < vk)
            {
                result = true;
                break;
            }

            if (vi == vj)
            {
                i++;
                j++;
            }

            if (vi > vk && vj > vk || ((vi == vk)|| (vj == vk)))
            {
                i++;
                j++;
            }
        }

        return result;
    }
};

int main()
{
    vector<vector<int>> vecTest = {
        {1, 2, 2, 1},
        {1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1},
        {2, 1, 5, 0, 4, 6},
        {20, 100, 10, 12, 5, 13}};

    Solution s;
    for (auto x : vecTest)
    {
        cout << s.increasingTriplet(x) << endl;
    }

    return 0;
}
