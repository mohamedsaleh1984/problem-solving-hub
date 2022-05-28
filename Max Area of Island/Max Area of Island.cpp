#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//https://leetcode.com/problems/max-area-of-island/
class Solution {
private:
	vector<vector<bool>> visited;
	vector<vector<int>> grid;
	int COLS;
	int ROWS;
	void printActions(vector<int> point, string action) {
		cout << action << " [" << point[0] << "," << point[1] << "]\n";
	}

public:
	void init(vector<vector<int>> grid) {
		this->grid = grid;
		for (int i = 0; i < grid.size(); i++)
		{
			vector<bool> row(grid[i].size());
			visited.push_back(row);
		}
		ROWS = grid.size();
		COLS = grid[0].size();
	}

	int maxAreaOfIsland(vector<vector<int>> grid) {
		init(grid);
		vector<int> islandSize = {};
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				if (grid[i][j] == 1 && visited[i][j] == false) {
					int size = computeIslandWidth(grid, i, j);
					islandSize.push_back(size);
				}
			}
		}
		if (islandSize.size()) {
			sort(islandSize.begin(), islandSize.end());
			return islandSize[islandSize.size() - 1];
		}
		return 0;
	}

	int computeIslandWidth(vector<vector<int>>& grid, int row, int col) {
		queue<vector<int>> negb;
		int iWidth = 1;
		negb.push({ row,col });
		//printActions({ row,col }, "Pushed");
			 
		while (negb.size()) {
			vector<int> vertex = negb.front();
			int row = vertex[0];
			int col = vertex[1];

			//mark visited 
			visited[row][col] = true;
			printActions(vertex, "Marked");
			//Remove it
			negb.pop();
			//printActions(vertex, "Removed from Queue");
			//right


			if (col + 1 < COLS && visited[row][col + 1] == false && grid[row][col + 1] == 1 ) {
				negb.push({ row, col + 1 });
				iWidth++;
				visited[row][col + 1] == true;
			//	printActions({ row, col + 1 }, "Pushed Right Neighbour");
			}
				
			//Left
			if (col - 1 >= 0 && visited[row][col - 1] == false && grid[row][col - 1] == 1) {

				negb.push({ row, col - 1 });
				iWidth++;
				visited[row][col - 1] == true;
			//	printActions({ row, col - 1 }, "Pushed Left Neighbour");
			}
				
			//up
			if (row - 1 >= 0 && visited[row - 1][col] == false && grid[row - 1][col] == 1) {
				negb.push({ row - 1, col });
				iWidth++;
				visited[row - 1][col] == false;
			//	printActions({ row - 1, col }, "Pushed Up Neighbour");
			}
				
			//down
			if (row + 1 < ROWS && visited[row + 1][col] == false && grid[row + 1][col] == 1) {
				negb.push({ row + 1, col });
				iWidth++;
				visited[row + 1][col] = true;
			//	printActions({ row + 1, col }, "Pushed Down Neighbour");
			}
			//printActions({ row,col }, "Moving to Next Vertex..");
		}
		return iWidth;
	}
};

int main()
{
	/*vector<vector<int>> grid= { {1,1,0,0,0},
								{1,1,0,0,0},
								{0,0,0,1,1},
								{0,0,0,1,1} 
								};*/
	vector<vector<int>> grid = { {1,1,0,1,0},
								 {1,0,1,1,0},
								 {1,1,1,1,1},
								 {1,0,1,1,1},
								 {0,0,1,0,1},
								 {0,0,0,1,0},
								 {1,1,1,0,1},
								 {0,1,1,1,0},
								 {0,1,0,1,0} };
	Solution s;
	cout << s.maxAreaOfIsland(grid) << endl;
	return 0;
}
