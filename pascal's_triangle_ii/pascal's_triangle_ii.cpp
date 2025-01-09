#include "../common.h"

// https://leetcode.com/problems/pascals-triangle-ii/
// Runtime: 4 ms, faster than 29.56% of C++ online submissions for Pascal's Triangle II.
class Solution
{
public:
	vector<int> getRow(int rowIndex)
	{
		vector<vector<int>> triangle = generate(rowIndex + 1);
		return triangle[rowIndex];
	}
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
	vector<int> result;
	Solution s = Solution();
	result = s.getRow(10);
	for (auto elem : result)
		cout << elem << " ";

	return 0;
}