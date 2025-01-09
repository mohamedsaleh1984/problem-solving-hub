#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    if (nums.size() == 0 || nums.size() == 1)
        return;

    int iLeft = 0;
    int iRight = 1;
    int size = nums.size();

    while (iRight < size)
    {

        if (nums[iLeft] == 0 && nums[iRight] != 0)
        {
            nums[iLeft] = nums[iRight];
            nums[iRight] = 0;

            iRight++;
            iLeft++;
        }
        else if (nums[iLeft] == 0 && nums[iRight] == 0)
        {
            iRight++;
        }
        else if (nums[iLeft] != 0 && nums[iRight] != 0)
        {
            iRight++;
            iLeft++;
        }
        else if (nums[iLeft] != 0 && nums[iRight] == 0)
        {
            iRight++;
            iLeft++;
        }
    }
}

int main()
{
    vector<int> nums = {1, 0};
    moveZeroes(nums);
}
