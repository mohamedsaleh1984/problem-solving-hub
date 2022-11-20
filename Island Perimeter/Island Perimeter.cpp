#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>
using namespace std;
//https://leetcode.com/problems/island-perimeter/
//TODO: Write the algo
class Solution {
private:
	vector<vector<bool>> visited;
	vector<vector<int>> grid;
	int COLS;
	int ROWS;
public:
	//void printActions(vector<int> point, string action) {
	//	cout << action << " [" << point[0] << "," << point[1] << "]\n";
	//}
	//
	//void viewGrid(vector<vector<int>> grid) {
	//	int rows = grid.size();
	//	int cols = grid[0].size();
	//	cout << "[";
	//	for (int i = 0; i < rows; i++)
	//	{
	//		cout << "[";
	//		for (int j = 0; j < cols; j++)
	//		{	
	//			cout << setw(2) << grid[i][j] << " ";
	//		}
	//		cout << "]";
	//		cout << endl;
	//	}
	//	cout << "]";
	//}

	//void init(vector<vector<int>> grid) {
	//	this->grid = grid;
	//	for (int i = 0; i < grid.size(); i++)
	//	{
	//		vector<bool> row(grid[i].size());
	//		visited.push_back(row);
	//	}
	//	ROWS = grid.size();
	//	COLS = grid[0].size();
	//}

	int islandPerimeter(vector<vector<int>>& grid) {
		int perimeter = 0;
		int rows = grid.size();
		int cols = grid[0].size();
		for (int iRow = 0; iRow < rows; iRow++)
		{
			int defaultPerimeter = 4;
			for (int iCol = 0; iCol < cols; iCol++)
			{
				if (grid[iRow][iCol] == 1)
				{
					//left 
					if (iCol > 0)
					{
						if (grid[iRow][iCol - 1] == 1)
							defaultPerimeter--;
					}
					//right
					if (iCol < grid[0].size() - 1)
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
					if (iRow < grid[0].size() - 1)
					{
						if (grid[iRow + 1][iCol] == 1)
							defaultPerimeter--;
					}
				}

			}
		}
		return perimeter;
	}

	//vector<vector<int>>  getNeighbour(int row, int col) {
	//	vector<vector<int>> negb;
	//	if (col + 1 < COLS && visited[row][col + 1] == false && grid[row][col + 1] == 1) {
	//		negb.push_back({ row, col + 1 });
	//	}

	//	//Left
	//	if (col - 1 >= 0 && visited[row][col - 1] == false && grid[row][col - 1] == 1) {
	//		negb.push_back({ row, col - 1 });
	//	}

	//	//up
	//	if (row - 1 >= 0 && visited[row - 1][col] == false && grid[row - 1][col] == 1) {
	//		negb.push_back({ row - 1, col });
	//	}

	//	//down
	//	if (row + 1 < ROWS && visited[row + 1][col] == false && grid[row + 1][col] == 1) {
	//		negb.push_back({ row + 1, col });
	//	}
	//	return negb;
	//}

	//bool IsVisisted(vector<int> vec) {
	//	return visited[vec[0]][vec[1]];
	//}

 //   int islandPerimeter(vector<vector<int>>& grid) {
	//	init(grid);
	//	vector<int> islandSize = {};

 //   }
};
int main()
{
	Solution s;

	vector<vector<int>> grid = { {0, 1, 0, 0}, { 1, 1, 1, 0 }, { 0, 1, 0, 0 }, { 1, 1, 0, 0 }};
	cout << s.islandPerimeter(grid);

    return 0;
}
