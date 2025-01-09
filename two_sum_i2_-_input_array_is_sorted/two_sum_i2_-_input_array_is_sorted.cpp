#include "../common.h"

vector<int> twoSum(vector<int> &numbers, int target)
{
    vector<int> result(2);
    int right = numbers.size() - 1;
    int left = 0;

    while (left < right)
    {
        if (numbers[left] + numbers[right] == target)
        {
            result[0] = left + 1;
            result[1] = right + 1;
            break;
        }
        else if (numbers[left] + numbers[right] < target)
        {
            left++;
        }
        else if (numbers[left] + numbers[right] > target)
        {
            right--;
        }
    }
    return result;
}

int main()
{
    vector<int> numbers = {-1, 0};
    int target = -1;
    vector<int> res = twoSum(numbers, target);

    return 0;
}
