#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

// TODO


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if(root == nullptr)
            return false;

        if(root->left || root->right)
            return false;
        
        if(root->left->val == root->right->val)
            return true;

    }
};

int main(void)
{
    // TreeNode* root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->left->left = new TreeNode(3);
    // root->left->right = new TreeNode(4);

    // root->right = new TreeNode(2);
    // root->right->left = new TreeNode(4);
    // root->right->right = new TreeNode(3);

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(2);

    root->right = new TreeNode(2);
    root->right->left = new TreeNode(2);

    Solution s;
    cout << "Result " << (s.isSymmetric(root) ? "True" : "False") << endl;

    return 0;
}

//  void inOrder(TreeNode *root, vector<int> &vec)
//     {
//         if (root == nullptr)
//             return;

//         inOrder(root->left, vec);
//         vec.push_back(root->val);
//         inOrder(root->right, vec);
//     }