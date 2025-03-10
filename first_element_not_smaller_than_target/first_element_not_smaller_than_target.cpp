#include "../common.h"

int first_not_smaller(std::vector<int> arr, int target)
{
    int result = -1;
    int left = 0, right = arr.size() - 1;
    int boundaryIndex = -1;
    vector<int> res = {};

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int elem = arr[mid];
        if (elem)
        {
            boundaryIndex = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return boundaryIndex;
}
int main()
{
    vector<int> v = {1, 3, 3, 5, 8, 8, 10};
    cout << first_not_smaller(v, 2) << endl;
    return 0;
}