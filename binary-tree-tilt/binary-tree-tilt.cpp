#include "../common.h"

class Solution
{
private:
    int gdiff = 0;

public:
    int treeSum(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return root->val + treeSum(root->left) + treeSum(root->right);
    }

    int findTilt(TreeNode *root)
    {
        int initialSum = 0;

        findTiltHelp(root,initialSum);

        return gdiff;
    }

    int findTiltHelp(TreeNode *root)
    {
        if(root == NULL)
        return 0;

        int newSum = root->val + sum;
        int left  =  findTiltHelp(root->left,newSum);
        int right  =  findTiltHelp(root->right,newSum);

        cout << "newSum " << newSum << endl;
        cout << "left  " << left << endl;
        cout << "right  " << right << endl;
        

        int diif = abs(left-right);

        return diif;

    }
};

int main(int argc, char **argv)
{
    // Level 1
    TreeNode *root = new TreeNode(4);
    // Level 2
    root->left = new TreeNode(2);
    root->right = new TreeNode(9);
    // Level 3
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(7);

    Solution s;

    cout << "Tilt" << s.findTilt(root) << endl;

    return 0;
}