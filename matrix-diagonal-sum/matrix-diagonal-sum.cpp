#include "../common.h"

// https://leetcode.com/problems/matrix-diagonal-sum/submissions/1445264251/
// 0ms Beats 100.00%
class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int size = mat.size();
        int odd = size % 2 == 1;
        int sum = 0;

        // top-left => down-right
        for (int i = 0, j = 0; i < mat.size(); i++, j++)
        {
            sum += mat[i][j];
        }

        // top-right => down-right
        for (int i = 0, j = mat.size() - 1; i < mat.size(); i++, j--)
        {
            sum += mat[i][j];
        }

        if (odd)
        {
            sum -= mat[size / 2][size / 2];
        }

        return sum;
    }
};

int main(void)
{
    // vector<vector<int>> vec = {{1, 2, 3},
    //                            {4, 5, 6},
    //                            {7, 8, 9}};

    vector<vector<int>> vec = {{1, 1, 1, 1},
                               {1, 1, 1, 1},
                               {1, 1, 1, 1},
                               {1, 1, 1, 1}};
    Solution s;
    cout << s.diagonalSum(vec) << endl;

    return 0;
}
