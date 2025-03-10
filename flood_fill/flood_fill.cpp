#include "../common.h"

//https://leetcode.com/problems/flood-fill/  
class Solution {
private:
	int ROWS;
	int COLS;
	vector<vector<int>> image;
	vector<vector<bool>> visited = {};
	int currentColor;
public:
	Solution(vector<vector<int>>& image, int sr, int sc) {
		this->image = image;
		ROWS = image.size();
		COLS = image[0].size();
		currentColor = image[sr][sc];
		for (int i = 0; i < image.size(); i++) {
			vector<bool> bTemp(COLS);
			visited.push_back(bTemp);
		}
	}

	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		queue<vector<int>> negb;
		negb.push({ sr,sc });
		while (negb.size()) {
			vector<int> vertex = negb.front();
			int row = vertex[0];
			int col = vertex[1];
			//mark visited 
			visited[row][col] = true;
			//Change it
			image[row][col] = newColor;
			//Remove it
			negb.pop();

			//right
			if (col + 1 < COLS && image[row][col + 1] == currentColor && visited[row][col + 1] == false)
				negb.push({ row, col + 1 });
			//Left
			if (col - 1 >= 0 && image[row][col - 1] == currentColor && visited[row][col - 1] == false)
				negb.push({ row, col - 1 });
			//up
			if (row - 1 >= 0 && image[row - 1][col] == currentColor && visited[row - 1][col] == false)
				negb.push({ row - 1, col });
			//down
			if (row + 1 < ROWS && image[row + 1][col] == currentColor && visited[row + 1][col] == false)
				negb.push({ row + 1, col });
		}
		return image;
	}
};

int main()
{
	/*
	vector<vector<int>> image = { {1, 1, 1}, {1, 1, 0}, {1, 0, 1} };
	int sr = 1, sc = 1, newColor = 2;
	*/
	vector<vector<int>> image = { {0,0,0}, {0,0, 0} };
	int sr = 0, sc = 0, newColor = 2;
	Solution sol(image,sr,sc);
	image = sol.floodFill(image, sr, sc, newColor);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++)
			cout << image[i][j] << " ";
		cout << endl;
	}

	return 0;
}