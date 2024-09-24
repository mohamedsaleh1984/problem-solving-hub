#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {

	bool hasZero = false;
	int zeros = 0;
	vector<int> result(nums.size());

	if (all_of(nums.cbegin(), nums.cend(), [](int i) { return i == 0; }))
	{
		fill(nums.begin(), nums.end(), 0);
		return result;
	}

	if (find(nums.begin(), nums.end(), 0) != nums.end()) {
		hasZero = true;
	}

	int product = 1;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] != 0)
			product *= nums[i];
		else
			zeros++;
	}

	if (!hasZero) {
		for (int i = 0; i < result.size(); i++)
			result[i] = product / nums[i];
	}
	else if(zeros == 1){
		for (int i = 0; i < result.size(); i++)
		{
			if (nums[i] != 0)
				result[i] = 0;
			else
				result[i] = product;
		}
	}
	else if(zeros > 1) {
		fill(nums.begin(), nums.end(), 0);	
	}

	return result;
}
int main()
{
	vector<int> nums = { -1,1,0,-3,3 };
	vector<int> result = productExceptSelf(nums);

	for (auto item : result)
		cout << item << " ";

	return 0;
}