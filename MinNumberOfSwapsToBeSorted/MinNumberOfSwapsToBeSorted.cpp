#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minSwap(int arr[], int N) {
	vector<pair<int, int>> Vec(N);
	for (int i = 0; i < N; ++i)
		Vec[i] = { arr[i],i };// {Item, Index}

	sort(Vec.begin(), Vec.end());

	int swaps = 0;

	for (int i = 0; i < N; ++i) {
		if (Vec[i].second != i)
		{
			++swaps;
			swap(Vec[i], Vec[Vec[i].second]);
			--i;
		}
	}
	return swaps;
}

int main()
{
	// swap 4,6
	// swap 2,1
	int arr[6] = {2,1,6,5,4,8};
	cout << minSwap(arr, 6) << endl; // 2

	return 0;
}

 