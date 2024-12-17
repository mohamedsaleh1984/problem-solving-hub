#include "../common.h"

// https://leetcode.com/problems/path-sum-ii
// 12/16/2024
// 19 ms Beats 9.56%

class Solution
{
private:
    void p(vector<int> c)
    {
        for (auto x : c)
        {
            cout << x << "_";
        }
    }
    int sum(vector<int> c)
    {
        int s = 0;
        for (auto x : c)
            s += x;
        return s;
    }
    vector<vector<int>> result;

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> entry;
        int curSum = 0;
        pathSumHelper(root, targetSum, entry, curSum);
        return result;
    }
    void pathSumHelper(TreeNode *root, int targetSum, vector<int> entry, int curSum)
    {

        if (root == nullptr)
        {
            return;
        }

        entry.push_back(root->val);
        curSum += root->val;
        if (curSum == targetSum && root->left == nullptr && root->right == nullptr)
        {
            result.push_back(entry);
            return;
        }
        pathSumHelper(root->left, targetSum, entry, curSum);
        pathSumHelper(root->right, targetSum, entry, curSum);

        entry.pop_back();
        curSum -= root->val;
    }
};

int main(int argc, char **argv)
{
    
    return 0;
}