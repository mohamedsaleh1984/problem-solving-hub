#include <iostream>
#include <vector>
#include <hashtable.h>
using namespace std;

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// 3ms Beats 56.77%

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        std::ios::sync_with_stdio(false);
        int elem = nums[0];
        for (int i = 0, j = i + 1; j < nums.size(); ++i, ++j)
        {
            if (nums[j] < nums[i])
            {
                elem = nums[j];
                break;
            }
        }
        return elem;
    }
};

int main(void)
{
    vector<int> nums = {11, 13, 15, 17};
    Solution s;
    int r = s.findMin(nums);
    cout << "res " << r << endl;

    return 0;
}