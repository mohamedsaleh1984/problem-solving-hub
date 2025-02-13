#include "../common.h"

int RangeSum(vector<int> arr, int i, int j)
{
	vector<int> vecSums(arr.size(), 0);
	vecSums[0] = (arr[0]);
	//Compute the incremental/compultive Sum of the List
	for (size_t i = 1, j = 0; i < arr.size(); i++, j++)
		vecSums[i] = vecSums[j] + arr[i];

	if (i == 0)
		return vecSums[j];
	//J element minus i elment which is the sum from i to j
	return vecSums[j] - vecSums[i - 1];
}

int main()
{
	vector<int> arr{ 1,5,8,10,7,8,9 };
	cout << RangeSum(arr, 0, 3) << endl;
	cout << RangeSum(arr, 3, 5) << endl;
	return 0;
}
