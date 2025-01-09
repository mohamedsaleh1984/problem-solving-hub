#include "../common.h"

//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int start = -1, end = -1;

        int searchResult = -1;

        searchResult = binary_search(nums, target);
        
        if (searchResult != -1) {
            start = end = searchResult;

            while (start >= 0 && nums[start] == target)
                start--;

            while (end < nums.size() && nums[end] == target)
                end++;
            result.push_back(start+1);
            result.push_back(end-1);
        }
        if (searchResult == -1) {
            result.push_back(-1);
            result.push_back(-1);

        }
        return result;
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
