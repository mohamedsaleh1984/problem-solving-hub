#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
private:
	vector<vector<bool>> visited;
	vector<vector<int>> grid;
	int COLS;
	int ROWS;
	int counter = 0;
	queue<vector<int>> rottenOranges;
	//Get all Not Rotten 
	vector<vector<int>>  getNeighbours(int row, int col) {
		vector<vector<int>> negb;
		if (col + 1 < COLS && !visited[row][col + 1] && grid[row][col + 1] == 1) {
			negb.push_back({ row, col + 1 });
		}
		//Left
		if (col - 1 >= 0 && !visited[row][col - 1] && grid[row][col - 1] == 1) {
			negb.push_back({ row, col - 1 });
		}
		//up
		if (row - 1 >= 0 && !visited[row - 1][col] && grid[row - 1][col] == 1) {
			negb.push_back({ row - 1, col });
		}
		//down
		if (row + 1 < ROWS && !visited[row + 1][col] && grid[row + 1][col] == 1) {
			negb.push_back({ row + 1, col });
		}
		return negb;
	}
	
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
public:
	int orangesRotting(vector<vector<int>>& grid) {
		init(grid);
		
		if (anyFresh()) {
			for (int i = 0; i < this->grid.size(); i++) {
				for (int j = 0; j < this->grid[0].size(); j++) {
					if (this->grid[i][j] == 2) {
						rottenOranges.push({ i,j });
					}
				}
			}
		}
		else {
			return 0;
		}
		

		while (!rottenOranges.empty()) {



			vector<int> vertex = rottenOranges.front();
			spreadRotten(vertex[0], vertex[1]);



		}


		if (anyFresh())
			return -1;
		return counter;
	}

	bool anyFresh() {
		for (int i = 0; i < this->grid.size(); i++)
		{
			for (int j = 0; j < this->grid[0].size(); j++)
			{
				if (this->grid[i][j] == 1)
					return true;
			}
		}
		return false;
	}

	void spreadRotten(int row, int col) {
		visited[row][col] = true;
		rottenOranges.pop();
		vector<vector<int>>  negb = getNeighbours(row, col);

		if (negb.size() > 0) {
			counter++;
		}

		vector<vector<int>>::iterator it;
		for (it = negb.begin(); it != negb.end(); it++) {
			vector<int> check = *it;
			rottenOranges.push(*it);
			this->grid[check[0]][check[1]] = 2;

		}
	}
};

int main()
{
	/*vector<vector<int>> grid = { {2,0,1,1,1,1,1,1,1,1},
								 {1,0,1,0,0,0,0,0,0,1},
								 {1,0,1,0,1,1,1,1,0,1},
								 {1,0,1,0,1,0,0,1,0,1},
								 {1,0,1,0,1,0,0,1,0,1},
								{1,0,1,0,1,1,0,1,0,1},
								{1,0,1,0,0,0,0,1,0,1},
								{1,0,1,1,1,1,1,1,0,1},
								{1,0,0,0,0,0,0,0,0,1},
								{1,1,1,1,1,1,1,1,1,1} };*/

	vector<vector<int>> grid = { {2, 1, 1}, { 1,1,1 }, { 0,1,2 } };

	Solution s = Solution();
	cout << s.orangesRotting(grid) << endl;
	return 0;
}
