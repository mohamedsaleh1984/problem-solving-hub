#include <iostream>
#include <vector>
using namespace std;
//https://leetcode.com/problems/triangle/
 //TODO: Fix it
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle[0].size() == 0)
            return 0;

        int ROWS = triangle.size();
        int COLS = triangle[ROWS - 1].size() + 1;

        int minimalVal = triangle[0][0];
        int rowIndex = 1;
        int colIndex = 0;

        for (int i = rowIndex; i < ROWS; ) {

            for (int j = colIndex; j < triangle[i].size();) {
                if (i > 0) {
                    int sameRow = minimalVal + triangle[i][j];
                    int sameRowNextColumn = minimalVal + triangle[i][j + 1];
                    if (sameRow < sameRowNextColumn) {
                        i++;
                        minimalVal = sameRow;
                        break;
                    }
                    else {
                        j++;
                        i++;
                        minimalVal = sameRowNextColumn;
                        break;
                    }
                }
            }
        }
        return minimalVal;
    }
};


int main()
{
    vector<vector<int>> grids2 = { {-1},{2,3},{1,-1,-3}};
    vector<vector<int>> grids = { {2},{3,4},{6,5,7},{4,1,8,3} };
    Solution s = Solution();
    cout << s.minimumTotal(grids2) << endl;
    return 0;
	return 0;
}

