#include "../common.h"

// https://leetcode.com/problems/product-of-array-except-self/

void print(vector<int> &res)
{
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
}
// 19ms Beats 94.97%
vector<int> productExceptSelf2(vector<int> &nums)
{
	vector<int> forward(nums.size());
	vector<int> backword(nums.size());
	vector<int> result(nums.size());

	int start = 1, end = 1;
	forward[0] = start;
	backword[nums.size() - 1] = start;

	for (int i = 1; i < nums.size(); i++)
	{
		start = start * nums[i - 1];
		forward[i] = start;
	}

	end = 1;
	for (int i = nums.size() - 2; i >= 0; i--)
	{
		end = end * nums[i + 1];
		backword[i] = end;
	}

	for (int i = 0; i < nums.size(); i++)
	{
		result[i] = forward[i] * backword[i];
	}



	return result;
}

// MEGA Imple
vector<int> productExceptSelf(vector<int> &nums)
{

	bool hasZero = false;
	int zeros = 0;
	vector<int> result(nums.size());

	// check if all elements in the array are zeros.
	if (all_of(nums.cbegin(), nums.cend(), [](int i)
			   { return i == 0; }))
	{
		// return default array which already initialized with zero
		return result;
	}

	// Check if we have zero value anywhere...
	if (find(nums.begin(), nums.end(), 0) != nums.end())
	{
		hasZero = true;
	}

	int product = 1;
	// Get the product of all elements except zero value.
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] != 0)
			product *= nums[i];
		else
			zeros++;
	}

	// if nums has zero
	if (!hasZero)
	{
		// over-write the element with total product / nums[i]
		for (int i = 0; i < result.size(); i++)
			result[i] = product / nums[i];
	} //
	else if (zeros == 1)
	{

		for (int i = 0; i < result.size(); i++)
		{
			if (nums[i] != 0)
				result[i] = 0;
			else
				result[i] = product;
		}
	} //
	else if (zeros > 1)
	{
		fill(nums.begin(), nums.end(), 0);
	}

	return result;
}

int main()
{
	vector<int> nums = {1, 2, 3, 4};
	vector<int> result = productExceptSelf2(nums);

	for (auto item : result)
		cout << item << " ";

	return 0;
}