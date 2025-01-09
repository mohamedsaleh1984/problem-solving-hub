#include "../common.h"
/*
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
*/
int binarySearch(vector<int> &numbers, int left, int right, int target)
{
    if (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (numbers[mid] == target)
            return mid;

        if (numbers[mid] > target)
        {
            return binarySearch(numbers, left, mid - 1, target);
        }
        return binarySearch(numbers, mid + 1, right, target);
    }

    return -1;
}

vector<int> twoSum(vector<int> &numbers, int target)
{
    vector<int> result(2);
    for (int i = 0; i < numbers.size(); i++)
    {

        int reminder = target - numbers[i];
        int index = binarySearch(numbers, i + 1, numbers.size() - 1, reminder);
        if (index != -1)
        {
            result[0] = i;
            result[1] = index;
            break;
        }
    }

    // Increase the indecies by 1
    result[0] = result[0] + 1;
    result[1] = result[1] + 1;
    return result;
}

int main()
{
    /*
    [3,24,50,79,88,150,345]
200
    */
    vector<int> numbers = {3, 24, 50, 79, 88, 150, 345};
    int target = 200;
    vector<int> res = twoSum(numbers, target);
    for (auto i : res)
    {
        cout << i << " ";
    }
    return 0;
}
