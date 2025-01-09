#include "../common.h"
//https://leetcode.com/problems/coloring-a-border/
//TODO: FIX
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

	vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {

		return grid;
	}

	vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
		return grid;
	}

	vector<vector<int>>  getNeighbour(int row, int col, int color) {
		vector<vector<int>> negb;
		if (col + 1 < COLS && visited[row][col + 1] == false && grid[row][col + 1] == color) {
			negb.push_back({ row, col + 1 });
		}

		//Left
		if (col - 1 >= 0 && visited[row][col - 1] == false && grid[row][col - 1] == color) {
			negb.push_back({ row, col - 1 });
		}

		//up
		if (row - 1 >= 0 && visited[row - 1][col] == false && grid[row - 1][col] == color) {
			negb.push_back({ row - 1, col });
		}

		//down
		if (row + 1 < ROWS && visited[row + 1][col] == false && grid[row + 1][col] == color) {
			negb.push_back({ row + 1, col });
		}
		return negb;
	}

	void colorComponent(vector<vector<int>> component, int color) {
		for (int i = 0; i < component.size(); i++) {
			grid[component[i][0]][component[i][1]] = color;
		}
	}

	bool IsVisisted(vector<int> vec) {
		return visited[vec[0]][vec[1]];
	}

	void findComponent(int row, int col, int color) {
		getNeighbour(row, col, color);

	}
};


int main()
{
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
	int row = 0, col = 0, color = 3;
	grid = s.colorBorder(grid, row, col, color);
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			cout << setw(2) << grid[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
