#include "../common.h"

// https://leetcode.com/problems/check-if-matrix-is-x-matrix/
//  0ms Beats 100.00%

class Solution
{
private:
public:
    void printout(vector<vector<int>> vec)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            for (int j = 0; j < vec[i].size(); j++)
                cout << setw(2) << vec[i][j] << " ";
            cout << endl;
        }
    }
    // All the elements in the diagonals of the matrix are non-zero.

    bool checkXMatrix(vector<vector<int>> &grid)
    {
        int size  = grid.size();
        // top-left => down-right
        for (int i = 0, j = 0; i < size; i++, j++)
        {
            if (grid[i][j] == 0)
                return false;
            else
                grid[i][j] = 0;
        }

        // top-right => down-right
        for (int i = 0, j = size - 1; i < size; i++, j--)
        {   
             if (i == size / 2 && j == size / 2)
                continue;
                
            if (grid[i][j] == 0)
                return false;
            else
                grid[i][j] = 0;
        }
        
        // Top
        for (int i = 1; i < size - 1; i++)
        {
            if (grid[0][i] != 0)
                return false;
        }

        // left
        for (int i = 1; i < size - 1; i++)
        {
            if (grid[i][0] != 0)
                return false;
        }

        // right
        for (int i = 1; i < size - 1; i++)
        {
            if (grid[i][size-1] != 0)
                return false;
        }
        

        // bottom
        for (int i = 1; i < size - 1; i++)
        {    
            if (grid[size-1][i] != 0)
                return false;
        }
    
        // center
        for(int i = 1 ;i < size-1 ; i++){
            for(int j =1; j < size-1 ;j++){
                if(grid[i][j] != 0){
                    return false;
                }
            }
        }

        return true;
    }
};

int main(void)
{
    Solution s;
    // vector<vector<int>> vec={{2,0,0,1},{0,3,1,0},{0,5,2,0},{4,0,0,2}};
    // vector<vector<int>> vec={{5,7,0},{0,3,1},{0,5,0}};
    // vector<vector<int>> vec = {{6, 0, 0, 0, 0, 0, 0, 18}, {0, 17, 0, 0, 0, 0, 18, 0}, {0, 0, 13, 0, 0, 17, 0, 0}, {0, 0, 0, 9, 18, 0, 0, 0}, {0, 0, 0, 2, 20, 0, 0, 0}, {0, 0, 20, 0, 0, 3, 0, 0}, {0, 14, 0, 0, 0, 0, 11, 0}, {19, 0, 0, 0, 0, 0, 0, 9}};

    vector<vector<int>> vec = {{5, 0, 20}, {0, 5, 0}, {6, 0, 2}};
    s.printout(vec);
    cout << (s.checkXMatrix(vec) ? "True" : "False") << endl;
    s.printout(vec);
    return 0;
}
