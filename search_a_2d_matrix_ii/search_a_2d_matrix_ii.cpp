#include "../common.h"
 
class Solution {
public:
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


	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int index = findRowIndex(matrix, target);
		if (index == -1)
			return false;

		return binary_search(matrix[index], target) != -1;
	}


	int findRowIndex(vector<vector<int>>& matrix, int target) {
		return -1;
	}
};


int main()
{
	vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
	vector<vector<int>> matrix2 = { {1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30} };
 
	Solution S;
	cout << S.searchMatrix(matrix, 5);
	cout << S.searchMatrix(matrix2, 20);
	return 0;
}