#include "../common.h"

// https://leetcode.com/problems/max-area-of-island/
class Solution
{
private:
	vector<vector<bool>> visited;
	vector<vector<char>> grid;
	int COLS;
	int ROWS;
	void printActions(vector<char> point, string action)
	{
		cout << action << " [" << point[0] << "," << point[1] << "]\n";
	}

public:
	void init(vector<vector<char>> grid)
	{
		this->grid = grid;
		for (int i = 0; i < grid.size(); i++)
		{
			vector<bool> row(grid[i].size());
			visited.push_back(row);
		}
		ROWS = grid.size();
		COLS = grid[0].size();
	}

	int numIslands(vector<vector<char>> &grid)
	{
		init(grid);
		vector<int> islandSize = {};
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[i].size(); j++)
			{
				if (grid[i][j] == '1' && visited[i][j] == false)
				{
					int width = 0;
					computeIsland(i, j, width);
					islandSize.push_back(width);
				}
			}
		}
		return islandSize.size();
	}

	vector<vector<int>> getNeighbour(int row, int col)
	{
		vector<vector<int>> negb;
		if (col + 1 < COLS && visited[row][col + 1] == false && grid[row][col + 1] == '1')
		{
			negb.push_back({row, col + 1});
		}

		// Left
		if (col - 1 >= 0 && visited[row][col - 1] == false && grid[row][col - 1] == '1')
		{
			negb.push_back({row, col - 1});
		}

		// up
		if (row - 1 >= 0 && visited[row - 1][col] == false && grid[row - 1][col] == '1')
		{
			negb.push_back({row - 1, col});
		}

		// down
		if (row + 1 < ROWS && visited[row + 1][col] == false && grid[row + 1][col] == '1')
		{
			negb.push_back({row + 1, col});
		}

		return negb;
	}

	bool IsVisisted(vector<int> vec)
	{
		return visited[vec[0]][vec[1]];
	}

	void computeIsland(int row, int col, int &width)
	{
		width++;
		visited[row][col] = true;
		vector<vector<int>> negb = getNeighbour(row, col);
		vector<vector<int>>::iterator it;
		for (it = negb.begin(); it != negb.end(); it++)
		{
			vector<int> check = *it;
			if (!IsVisisted(check))
				computeIsland(check[0], check[1], width);
		}
	}
};

int main()
{
	vector<vector<char>> grid = {
		{'1', '1', '0', '0', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '1', '0', '0'},
		{'0', '0', '0', '1', '1'}};
	Solution s;
	cout << s.numIslands(grid) << endl;
	return 0;
}
