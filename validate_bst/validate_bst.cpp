
#include <iostream>
#include <vector>
using namespace std;


//https://leetcode.com/problems/validate-binary-search-tree
//


struct TreeNode
{
    int val;         // The data in this node.
    TreeNode *left;  // Pointer to the left subtree.
    TreeNode *right; // Pointer to the right subtree.

    TreeNode(int i)
    {
        // Constructor.  Make a node containing str.
        val = i;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
      bool isValidBST(TreeNode* root) 
      {
        vector<int> res =  inOrder(root);

        for(int i= 0, j = 1; j < res.size() ; j++, i++){
            if(res[j] <= res[i])
                return false;
        }
        return true;
      }

    vector<int> inOrder(TreeNode* root){
        vector<int> result;
        inOrderHelper(root,result);
        return result;
    }
    void inOrderHelper(TreeNode* root,vector<int>& res){
        if(root == nullptr)return;
        inOrderHelper(root->left,res);
        res.push_back(root->val);
        inOrderHelper(root->right,res);
    }
};

int main(void)
{
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    Solution s;
    cout << s.isValidBST(root) << endl;
    return 0;
}

    bool isValidBST(TreeNode* root) {
        if(root == nullptr )
            return true;

        if(root->left==nullptr && root->right == nullptr)
            return true;

        int rootVal = root->val;

        if(root->left != nullptr &&
            root->right  == nullptr &&
            root->left->val < rootVal)
        {
            return true;
        }
        
        if(root->right != nullptr &&
            root->left == nullptr &&
            root->right->val > rootVal)
        {
            return true;
        }
        
        if( root->left != nullptr &&
            root->right != nullptr && 
            root->left->val < rootVal &&
             root->right->val > rootVal)
        {
            return true;
        }
        else{
            return false;
        }

        return (isValidBST(root->left)  && isValidBST(root->right));
    }
