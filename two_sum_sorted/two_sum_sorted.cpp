#include "../common.h"

std::vector<int> two_sum_sorted(std::vector<int> arr, int target) {
    vector<int> res;
    int leftPtr = 0, rightPtr = arr.size() - 1;
    while (leftPtr < rightPtr) {
        int leftNum = arr[leftPtr];
        int rightNum = arr[rightPtr];
        int expected = leftNum + rightNum;

        if (expected == target) {
            res.push_back(leftPtr);
            res.push_back(rightPtr);
            break;
        }
        else {
            if (expected > target) {
                rightPtr--;
            }
            else {
                leftPtr++;
            }
        }
    }
    return res;
}

int main()
{
    vector<int> vec = { 2, 3, 5, 8, 11, 15 };
    vector<int> res = two_sum_sorted(vec, 5);
    for (int x : res) {
        cout << x << " ";
    }
    return 0;
}
