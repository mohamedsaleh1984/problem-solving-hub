// Count Good Nodes in Binary Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <set>
using namespace std;

//TODO: implement the algo
//https://leetcode.com/problems/count-good-nodes-in-binary-tree/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
};

class Solution {
public:
    int goodNodes(TreeNode* root) {
        int goodNodesCount = 1;
        goodNodesHelper(root, true, goodNodesCount);
        return goodNodesCount;
    }

    void goodNodesHelper(TreeNode* root, bool isGood, int& nums) {
        if (root == nullptr) {
            return;
        }

        if (root->left != nullptr && root->left->val > root->val) {
           return  goodNodesHelper(root->left, true, nums + 1);
        }
        else {
            return  goodNodesHelper(root->left, false, nums);
        }

        if (root->right != nullptr && root->right->val > root->val) {
            return  goodNodesHelper(root->right, true, nums + 1);
        }
        else {
            return  goodNodesHelper(root->right, false, nums);
        }


    }
};



/* utility that allocates a new node with the
given data and NULL left and right pointers. */
TreeNode* newnode(int data)
{
    TreeNode* Node = new TreeNode();
    Node->val = data;
    Node->left = NULL;
    Node->right = NULL;

    return(Node);
}


int main()
{
    //TreeNode* root = newnode(3);
    //root->left = newnode(1);
    //root->right = newnode(4);
    //root->left->left = newnode(3);
    //root->right->right = newnode(5);
    //root->right->left = newnode(1);

    TreeNode* root = newnode(2);
    root->right= newnode(4);
    root->right->left = newnode(10);
    root->right->left->left = newnode(8);
    root->right->left->right = newnode(4);

    cout << goodNodes(root) << endl;
}
 