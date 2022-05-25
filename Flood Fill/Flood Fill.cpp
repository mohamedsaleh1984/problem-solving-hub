#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <stdexcept>
using namespace std;

//https://leetcode.com/problems/flood-fill/
//TODO: continue work on it.    
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

    }

    vector<tuple<int, int>> adjacentWithSameColors(vector<vector<int>>& image, int row, int col) {
        vector<tuple<int, int>> result = {};
        int currentColor = image[row][col];

        //right
        if (col + 1 < image[0].size() && image[row][col + 1] == currentColor)
            result.push_back(std::make_tuple(row,col+1));
        //Left
        if (col - 1 >= 0 && image[row][col - 1] == currentColor)
            result.push_back(std::make_tuple(row, col - 1));
        //up
        if (row - 1 >= 0 && image[row-1][col] == currentColor)
            result.push_back(std::make_tuple(row-1, col));
        //down
        if (row + 1 < image.size() && image[row - 1][col] == currentColor)
            result.push_back(std::make_tuple(row + 1, col));

        return result;
    }
};


int main()
{
    vector<vector<int>> image = { {1, 1, 1}, {1, 1, 0}, {1, 0, 1} };
    int sr = 1, sc = 1, newColor = 2;
    Solution sol;

    vector<tuple<int, int>> adjacentWithSameColorsResult = sol.adjacentWithSameColors(image, sr, sc);
	return 0;
}
