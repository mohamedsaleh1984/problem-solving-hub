#include "../common.h"

// https://leetcode.com/problems/triangle/
// hint: start from the bottom up

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        if (triangle[0].size() == 0)
            return 0;

        int ROWS = triangle.size();
        for (int i = ROWS - 1; i >= 0; i--)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                if (i < ROWS - 1)
                {
                    triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
                }
            }
        }
        return triangle[0][0];
    }
};

int main()
{
    vector<vector<int>> grids2 = {{-1}, {2, 3}, {1, -1, -3}};
    vector<vector<int>> grids = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    Solution s = Solution();
    cout << s.minimumTotal(grids) << endl;
    return 0;
}
