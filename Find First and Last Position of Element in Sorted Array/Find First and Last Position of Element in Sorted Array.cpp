#include <iostream>
#include <vector>
using namespace std;

//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
//TODO: Write it

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

    }
    int binary_search(std::vector<int> arr, int target) {
        int result = -1;
        int l = 0, r = arr.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            int elem = arr[mid];

            if (elem == target)
            {
                result = mid;
                break;
            }
            else if (elem > target) {

                r = mid - 1;
            }
            else if (elem < target) {
                l = mid + 1;
            }
        }


        return result;
    }

};

int main()
{
	vector<int> nums = { 5, 7, 7, 8, 8, 10 };
	int target = 8;


	return 0;
}