#include "../common.h"

// https://leetcode.com/problems/minimum-path-sum/
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        if (grid[0].size() == 0)
            return 0;

        int ROWS = grid.size();
        int COLS = grid[0].size();

        vector<vector<int>> dp(grid.size());

        for (int i = 0; i < ROWS; i++)
            dp[i].resize(COLS);

        for (int i = 0; i < ROWS; i++)
        {

            for (int j = 0; j < COLS; j++)
            {

                dp[i][j] += grid[i][j];

                if (i > 0 && j > 0)
                {
                    // find the minimal between the previous column, previous row
                    dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]);
                }
                else if (i > 0)
                {
                    dp[i][j] += dp[i - 1][j];
                }
                else if (j > 0)
                {
                    dp[i][j] += dp[i][j - 1];
                }
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        return dp[ROWS - 1][COLS - 1];
    }
};

int main()
{
    vector<vector<int>> grids = {{1, 2, 3}, {4, 5, 6}};
    Solution s = Solution();
    cout << s.minPathSum(grids) << endl;
    return 0;
}
