#include <iostream>
#include <vector>
using namespace std;

//https://leetcode.com/problems/merge-sorted-array/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr1 = m - 1;
        int ptr2 = n - 1;

        if (m == 0) {
            nums1.resize(nums2.size());
            ptr1 = nums1.size() - 1;
        }


        int lastIndex = nums1.size() - 1;
        
        while (ptr1 >= 0 && ptr2 >= 0) {
            if (nums1[ptr1] >= nums2[ptr2]) {
                nums1[lastIndex] = nums1[ptr1--];
            }
            else {
                nums1[lastIndex] = nums2[ptr2--];
            }
            lastIndex--;
        }

        for (int i = 0; i < nums1.size(); i++)
            cout << nums1[i] << " ";
    }
};

int main()
{
    vector<int> nums1 = {0};
    int m = 0;
    vector<int> nums2 = { 2,5,6 };
    int n = 3;
    Solution s;
    s.merge(nums1, m, nums2, n);

}
 