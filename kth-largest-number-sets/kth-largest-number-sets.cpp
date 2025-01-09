#include "../common.h"

// using sets
// TODO: fix
int findKthLargestApp2(vector<int> &nums, int k)
{
    int largestKth = 0;
    set<int> noDuploactes;
    for (int i = 0; i < nums.size(); i++)
        noDuploactes.insert(nums[i]);

    vector<int> sortedValues(noDuploactes.begin(), noDuploactes.end());
    sort(sortedValues.rbegin(), sortedValues.rend());

    for (int i = 0; i < sortedValues.size(); i++)
        cout << sortedValues[i] << " ";
    /*
    cout << sortedValues[k] << " --- " << sortedValues[k - 1] << endl;
     */
    largestKth = 9999; // sortedValues[k];
    return largestKth;
}

int main()
{
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << findKthLargestApp2(nums, 4) << endl;
    return 0;
}
