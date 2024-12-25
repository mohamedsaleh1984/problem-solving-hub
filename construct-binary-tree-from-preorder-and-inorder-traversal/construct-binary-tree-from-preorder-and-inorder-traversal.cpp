#include "../common.h"

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
// FIX_IT
class Solution
{
public:
    TreeNode *buildBST(vector<int> nodes)
    {
        int left = 0;
        int right = nodes.size();
        TreeNode *root = creatBST(nodes, 0, right - 1);
        return root;
    }
    TreeNode *creatBST(vector<int> nums, int L, int R)
    {
        if (R < L)
            return NULL;

        int middle = (R + L) / 2;

        TreeNode *root = new TreeNode(nums[middle]);
        root->left = creatBST(nums, L, middle - 1);
        root->right = creatBST(nums, middle + 1, R);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        TreeNode *root = new TreeNode(preorder[0]);
        int rootIndex = findRootIndex(inorder, preorder[0]);

        vector<int> leftSide;
        vector<int> rightSide;

        copy(inorder.begin() + 0, inorder.begin() + rootIndex, back_inserter(leftSide));
        copy(inorder.begin() + rootIndex + 1, inorder.end(), back_inserter(rightSide));

        root->left = creatBST(leftSide, 0, leftSide.size() - 1);
        root->right = creatBST(rightSide, 0, rightSide.size() - 1);

        return root;
    }

    int findRootIndex(vector<int> inorder, int rootValue)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            if (rootValue == inorder[i])
            {
                return i;
            }
        }
        return -1;
    }
};

int main(int argc, char **argv)
{

    vector<int> pre = {3, 9, 20, 15, 7};
    vector<int> ino = {9, 3, 15, 20, 7};

    Solution s;
    // TreeNode *root = s.buildBST(pre);

    TreeNode *root = s.buildTree(pre, ino);

    inorder(root);

    return 0;
}