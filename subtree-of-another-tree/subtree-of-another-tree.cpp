
// Single Number - HashMap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    bool isSameTree(TreeNode* root, TreeNode* subRoot){
        if(root == nullptr && subRoot == nullptr){
            return true;
        }
        else if(root == nullptr || subRoot == nullptr){
            return false;
        }


        // check value
        if(root-> val != subRoot->val)
            return false;

        bool leftRec = isSameTree(root->left, subRoot->left);
        bool rightRec = isSameTree(root->right, subRoot->right);

        return leftRec && rightRec;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(root == nullptr)
            return false;


        if(root-> val == subRoot-> val)
        {
            if(isSameTree(root,subRoot))
                return true;
        }

        if(isSubtree(root->left, subRoot))
            return true;

        if(isSubtree(root->right, subRoot))
            return true;

        return false;
    }
};

int main()
{
	
	return 0;
}
