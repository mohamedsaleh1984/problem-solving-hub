#include "../common.h"

//https://leetcode.com/problems/island-perimeter/
class Solution {
private:
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		int perimeter = 0;
		int rows = grid.size();
		int cols = grid[0].size();
		for (int iRow = 0; iRow < rows; iRow++)
		{
			for (int iCol = 0; iCol < cols; iCol++)
			{
				int defaultPerimeter = 4;
				if (grid[iRow][iCol] == 1)
				{
					//left 
					if (iCol > 0)
					{
						if (grid[iRow][iCol - 1] == 1)
							defaultPerimeter--;
					}
					//right
					if (iCol < cols - 1)
					{
						if (grid[iRow][iCol + 1] == 1)
							defaultPerimeter--;
					}
					//up
					if (iRow > 0)
					{
						if (grid[iRow - 1][iCol] == 1)
							defaultPerimeter--;
					}

					//down
					if (iRow < rows - 1)
					{
						if (grid[iRow + 1][iCol] == 1)
							defaultPerimeter--;
					}

					perimeter += defaultPerimeter;
				}

			}
		}
		return perimeter;
	}
};
int main()
{
	Solution s;
	vector<vector<int>> grid1 = { {0, 1, 0, 0}, { 1, 1, 1, 0 }, { 0, 1, 0, 0 }, { 1, 1, 0, 0 }};
	vector<vector<int>> grid = { {1,0}};
	cout << s.islandPerimeter(grid);

    return 0;
}
