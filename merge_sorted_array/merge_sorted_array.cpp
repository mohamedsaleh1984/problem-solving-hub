#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/merge-sorted-array/
//
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int p1 = 0;
        int p2 = 0;
        int zeroIndex = m;

        while (p2 < nums2.size())
        {

            if (nums1[p1] <= nums2[p2])
            {
                // right place, move left pointer forward
                p1++;
            }
            else
            {
                // right side less than left side
                if (nums2[p2] < nums1[p1])
                {
                    // shift elements one cell
                    int zeroTemp = zeroIndex;
                    while (zeroTemp > p1)
                    {
                        nums1[zeroTemp] = nums1[zeroTemp - 1];
                        zeroTemp--;
                    }
                    zeroIndex++;

                    // place the element from righ to left side
                    nums1[p1] = nums2[p2++];
                }
                else
                {
                    nums1[zeroIndex] = nums2[p2];
                    p2++;
                    zeroIndex++;
                    p1 = zeroIndex - 1;
                }
            }
        }
    }
};

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    // vector<int> nums1 = {1}; int m = 1;
    // vector<int> nums2 = {}; int n = 0;

    // vector<int> nums1 = {0}; int m = 0;
    // vector<int> nums2 = {1}; int n = 1;

    // vector<int> nums1 = {4,5,6,0,0,0}; int m = 3;
    // vector<int> nums2 = {1,2,3}; int n = 3;

    // vector<int> nums1 = {-1,0,0,3,3,3,0,0,0}; int m = 6;
    // vector<int> nums2 = {1,2,2}; int n = 3;

    Solution s;
    s.merge(nums1, m, nums2, n);

    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1.at(i) << " ";
    }
}
