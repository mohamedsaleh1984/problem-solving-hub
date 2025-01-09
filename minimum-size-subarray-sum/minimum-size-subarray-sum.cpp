#include "../common.h"

// https://leetcode.com/problems/minimum-size-subarray-sum/
// 0ms Beats 100.00%

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int res = INT_MAX;
        int left = 0, right = 0;
        int len = nums.size();
        int currentSum = 0;

        while (right < len)
        {
            currentSum += nums[right];
            while (currentSum >= target)
            {
                res = min(res, right - left + 1);

                currentSum -= nums[left];
                left++;
            }
            right++;
        }
        return res == INT_MAX ? 0 : res;
    }
};

int main(int argc, char **argv)
{
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1};
    Solution s;
    cout << s.minSubArrayLen(7, nums) << endl;

    return 0;
}