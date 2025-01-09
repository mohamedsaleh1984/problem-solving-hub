#include "../common.h"

int find_boundary(std::vector<bool> arr)
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
int find_boundary2(std::vector<bool> arr)
{
    int result = -1;
    int left = 0, right = arr.size() - 1;
    vector<int> res = {};

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int elem = arr[mid];
        if (elem)
        {
            right = mid - 1;
            res.push_back(mid);
        }
        else
        {
            left = mid + 1;
        }
    }

    if (res.size())
    {
        result = *min_element(res.begin(), res.end());
    }

    return result;
}

int main()
{
    vector<bool> v = {false, false, true, true, true};
    cout << find_boundary(v) << endl;
    return 0;
}
