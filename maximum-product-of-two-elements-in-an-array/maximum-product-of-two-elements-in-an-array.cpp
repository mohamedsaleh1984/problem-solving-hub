
#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/submissions/1445365629/
// 6 ms Beats8.50%
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int maxValue = -1;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                maxValue = max(maxValue, (nums[i] - 1) * (nums[j] - 1));
            }
        }
        return maxValue;
    }
};

int main(void)
{

    vector<int> nums = {3, 4, 5, 2};
    Solution s;
    s.maxProduct(nums);

    return 0;
}
