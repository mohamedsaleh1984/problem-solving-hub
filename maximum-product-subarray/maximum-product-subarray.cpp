#include "../common.h"
/*
    https://leetcode.com/problems/maximum-product-subarray/submissions/
    3ms Beats 85.56%
 */

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int result = nums[0];
        int prevMax = nums[0];
        int prevMin = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {

            int currMax = max(nums[i], max(prevMax * nums[i], prevMin * nums[i]));
            int currMin = min(nums[i], min(prevMax * nums[i], prevMin * nums[i]));

            prevMin = currMin;
            prevMax = currMax;

            result = max(prevMax, result);
        }

        return result;
    }
};

int main(void)
{
    return 0;
}