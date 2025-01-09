#include "../common.h"

// https://leetcode.com/problems/pascals-triangle/
// Runtime: 4 ms, faster than 24.36% of C++ online submissions for Pascal's Triangle.
class Solution
{
public:
	vector<vector<int>> generate(int numRows)
	{
		vector<vector<int>> result;
		if (numRows == 1)
		{
			vector<int> vec = {1};
			result.push_back(vec);
			return result;
		}
		else
		{
			for (int i = 0; i < numRows; i++)
			{
				vector<int> vec(i + 1);
				result.push_back(vec);
			}
			result[0][0] = 1;
			result[1][0] = 1;
			result[1][1] = 1;
		}

		for (int i = 2; i < numRows; i++)
		{
			for (int j = 0; j < result[i].size(); j++)
			{
				if (j == 0 || j == result[i].size() - 1)
				{
					result[i][j] = 1;
				}
				else
				{
					result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
				}
			}
		}

		return result;
	}
};

int main()
{
	vector<vector<int>> result;
	Solution sol = Solution();
	result = sol.generate(5);
	for (auto vec : result)
	{
		for (auto elem : vec)
			cout << elem << " ";
		cout << endl;
	}

	return 0;
}
/*
 int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle[0].size() == 0)
			return 0;

		int ROWS = triangle.size();
		int COLS = triangle[ROWS - 1].size() + 1;

		int minimalVal = triangle[0][0];
		int rowIndex = 1;
		int colIndex = 0;

		for (int i = rowIndex; i < ROWS; ) {

			for (int j = colIndex; j < triangle[i].size();) {
				if (i > 0) {
					int sameRow = minimalVal + triangle[i][j];
					int sameRowNextColumn = minimalVal + triangle[i][j + 1];
					if (sameRow < sameRowNextColumn) {
						i++;
						minimalVal = sameRow;
						break;
					}
					else {
						j++;
						i++;
						minimalVal = sameRowNextColumn;
						break;
					}
				}
			}
		}
		return minimalVal;
	}
*/