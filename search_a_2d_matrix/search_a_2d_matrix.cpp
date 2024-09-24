#include <iostream>
#include <vector>
using namespace std;
/*
https://leetcode.com/problems/search-a-2d-matrix/submissions/
Runtime: 10 ms, faster than 18.63% of C++ online submissions for Search a 2D Matrix.
Memory Usage: 9.6 MB, less than 5.81% of C++ online submissions for Search a 2D Matrix.

*/
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
		int index = findIndexOfRow(matrix, target);
		if (index == -1)
			return false;

		return binary_search(matrix[index], target) != -1;
	}

	int findIndexOfRow(vector<vector<int>>& matrix, int target) {
		for (int i = 0; i < matrix.size(); i++)
		{
			int cols = matrix[i].size();
			if (matrix[i][cols - 1] >= target)
				return i;
		}
		return -1;
	}
};



int main()
{
	vector<vector<int>> matrix = { {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60} };
	vector<vector<int>> matrix2 = { {0} };
	vector<vector<int>> matrix3 = { {1} };
	Solution S;
	cout << S.searchMatrix(matrix, 11);
	cout << S.searchMatrix(matrix2, 1);
	cout << S.searchMatrix(matrix3, 1);

	return 0;
}