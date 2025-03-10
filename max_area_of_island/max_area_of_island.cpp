#include "../common.h"
// https://leetcode.com/problems/max-area-of-island/
// 47ms Beats 5.01%

class Solution
{
private:
	vector<vector<bool>> visited;
	vector<vector<int>> grid;
	int COLS;
	int ROWS;
	void printActions(vector<int> point, string action)
	{
		cout << action << " [" << point[0] << "," << point[1] << "]\n";
	}

public:
	int numberOfIslands;
	void init(vector<vector<int>> grid)
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

	int maxAreaOfIsland(vector<vector<int>> grid)
	{
		init(grid);
		vector<int> islands = {};

		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[i].size(); j++)
			{
				//
				if (grid[i][j] == 1 && visited[i][j] == false)
				{

					int width = 0;

					computeIslandWidth(i, j, width);

					islands.push_back(width);
				}
			}
		}

		if (islands.size())
		{
			numberOfIslands = islands.size();
			sort(islands.begin(), islands.end());
			return islands[islands.size() - 1];
		}

		return 0;
	}

	vector<vector<int>> getNeighbour(int row, int col)
	{
		vector<vector<int>> negb;

		// right
		if (col + 1 < COLS && visited[row][col + 1] == false && grid[row][col + 1] == 1)
		{
			negb.push_back({row, col + 1});
		}

		// Left
		if (col - 1 >= 0 && visited[row][col - 1] == false && grid[row][col - 1] == 1)
		{
			negb.push_back({row, col - 1});
		}

		// up
		if (row - 1 >= 0 && visited[row - 1][col] == false && grid[row - 1][col] == 1)
		{
			negb.push_back({row - 1, col});
		}

		// down
		if (row + 1 < ROWS && visited[row + 1][col] == false && grid[row + 1][col] == 1)
		{
			negb.push_back({row + 1, col});
		}

		return negb;
	}

	bool IsVisisted(vector<int> vec)
	{
		return visited[vec[0]][vec[1]];
	}

	void computeIslandWidth(int row, int col, int &width)
	{
		//
		width++;
		visited[row][col] = true;
		vector<vector<int>> negb = getNeighbour(row, col);
		vector<vector<int>>::iterator it;
		for (it = negb.begin(); it != negb.end(); it++)
		{
			vector<int> check = *it;
			if (!IsVisisted(check))
				computeIslandWidth(check[0], check[1], width);
		}
	}
};

int main()
{
	/*vector<vector<int>> grid= {
								{1,1,0,0,0},
								{1,1,0,0,0},
								{0,0,0,1,1},
								{0,0,0,1,1}
								};
								*/
	vector<vector<int>> grid = {{1, 1, 0, 1, 0},
								{1, 0, 1, 1, 0},
								{1, 1, 1, 1, 1},
								{1, 0, 1, 1, 1},
								{0, 0, 1, 0, 1},
								{0, 0, 0, 1, 0},
								{1, 1, 1, 0, 1},
								{0, 1, 1, 1, 0},
								{0, 1, 0, 1, 0}};
	Solution s;

	cout << s.maxAreaOfIsland(grid) << endl;
	cout << s.numberOfIslands << endl;

	return 0;
}
