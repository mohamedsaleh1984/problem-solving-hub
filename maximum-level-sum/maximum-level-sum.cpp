#include "../common.h"

// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/?envType=study-plan-v2&envId=leetcode-75
// 12/15/2024
// 7 ms Beats 35.92%

class Solution
{
private:
    map<int, int> levelSum;

public:
    int maxLevelSum(TreeNode *root)
    {
        int maxLevels = getLevel(root);
        maxLevelSumHelper(root, maxLevels);
        return getLevelWithMaxSum();
    }

    int getLevel(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int l = 1 + getLevel(root->left);
        int r = 1 + getLevel(root->right);
        return max(l, r);
    }

    void maxLevelSumHelper(TreeNode *root, int max)
    {
        stack<TreeNode *> s;
        s.push(root);
        queue<TreeNode *> Q;
        int level = 1;
        while (level <= max)
        {
            int sum = 0;

            while (!s.empty())
            {
                TreeNode *n = s.top();
                sum += n->val;

                if (n->left)
                {
                    Q.push(n->left);
                }

                if (n->right)
                {
                    Q.push(n->right);
                }
                s.pop();
            }
        
            levelSum.insert({level, sum});

            while (!Q.empty())
            {
                s.push(Q.front());
                Q.pop();
            }

            level++;
        }
    }

    int getLevelWithMaxSum()
    {
        int level = 0;
        int curSum = INT_MIN;
        for (const auto &x : levelSum)
        {
            if (x.second > curSum)
            {
                level = x.first;
                curSum = x.second;
            }
        }
        return level;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    TreeNode* root =  new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);

    cout << s.maxLevelSum(root) << endl;

    return 0;
}
