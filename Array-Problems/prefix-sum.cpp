#include "../common.h"

void prefixSum(vector<int> &nums)
{
    for (int i = 1; i < nums.size(); i++)
        nums[i] += nums[i - 1];
}

int range_sum(vector<int> &nums, int from, int to)
{
    if (from == 0)
        return nums[to];
    return nums[to] - nums[from - 1];
}

/*
    given an array of integers, find the maximum difference between two elements such that the larger number appears after the smaller number
 */
// brut force
// O(n^2)
int maxDiffv1(vector<int> nums)
{
    int ans = INT_MIN;
    for (int i = 0; i < (int)nums.size(); i++)
    {
        for (int j = i + 1; j < (int)nums.size(); ++j)
        {
            // the number of the left side smaller
            // than the current element on the right
            if (nums[i] < nums[j])
                ans = max(ans, nums[j] - nums[i]);
        }
    }
    return ans;
}

// using max-suffix, from back to front
/*
Explanation:
- The function computes the maximum difference between any two elements in the array such that the larger element appears after the smaller one.
- mx_so_far keeps track of the largest value encountered while traversing the array from right to left.
- ans stores the maximum difference found during the traversal. If no valid pair is found, it remains INT_MIN.
 */
int maxDiffv2(vector<int> nums)
{
    // Initialize the maximum difference as the smallest possible integer value
    int ans = INT_MIN;

    // Set the maximum value encountered so far to the last element of the vector
    int mx_so_far = nums.back();

    // Traverse the vector from the second last element to the first
    for (int i = (int)nums.size() - 2; i >= 0; --i)
    {
        // Check if the current element is smaller than the maximum so far
        if (nums[i] < mx_so_far)
        {
            // Update the maximum difference if the difference with the current element is greater
            ans = max(ans, mx_so_far - nums[i]);
        }

        // Update the maximum value encountered so far to include the current element
        mx_so_far = max(mx_so_far, nums[i]);
    }

    // Return the maximum difference found
    return ans;
}

// Brute force O(n^3)
int subarraySumV1(vector<int> &nums, int k)
{
    int res = 0;

    for (int start = 0; start < (int)nums.size(); ++start)
    {

        for (int end = start; end < (int)nums.size(); ++end)
        {

            int cur_sum = 0;

            for (int idx = start; idx <= end; ++idx)
                cur_sum += nums[idx];

            if (cur_sum == k)
                ++res;
        }
    }

    return res;
}

// O(N^2)
int subarraySumV2(vector<int> &nums, int k)
{
    int res = 0;
    prefixSum(nums);

    for (int start = 0; start < (int)nums.size(); ++start)
    {
        for (int end = start; end < (int)nums.size(); ++end)
        {
            if (range_sum(nums, start, end) == k)
            {
                res++;
            }
        }
    }

    return res;
}

// O(N)
int subarraySum(vector<int>& nums, int k) {	// O(n)
		unordered_map<int, int> prefix_table;
		prefix_table[0] = 1;	// prefix 0 always there
		int res = 0, prefix_sum = 0;

		for (int i = 0; i < (int) nums.size(); i++) {
			prefix_sum += nums[i];

			if (prefix_table.count(prefix_sum - k))
				res += prefix_table[prefix_sum - k];

			++prefix_table[prefix_sum];
		}

		return res;
	}

int main()
{
    vector<int> nums = {1, 2, 6, 8, 4, 74, 1, 39};
    cout << "before " << endl;
    printvector(nums);
    cout << endl;
    prefixSum(nums);
    cout << "after " << endl;
    printvector(nums);
    cout << "MAX DIFF v1" << endl;
    cout << maxDiffv1(nums) << endl;
    cout << "MAX DIFF v2" << endl;
    cout << maxDiffv2(nums) << endl;
}