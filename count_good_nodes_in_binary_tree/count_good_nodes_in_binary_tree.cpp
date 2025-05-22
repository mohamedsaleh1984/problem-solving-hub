#include "../common.h"

//https://leetcode.com/problems/count-good-nodes-in-binary-tree/
/*
Runtime: 161 ms, faster than 65.61% of C++ online submissions for Count Good Nodes in Binary Tree.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
/*
      int goodNodes(TreeNode* root) {
		int currentMax = root->val;
		int mxLeft = goodNodesHelper(root->left, currentMax);
		int mxRight = goodNodesHelper(root->right, currentMax);
		return mxLeft + mxRight+1;
	}

	int goodNodesHelper(TreeNode* root, int currentMax) {
		if (root == nullptr) {
			return 0;
		}

		if (root->val >= currentMax ) {
			currentMax = root->val;
			return 1 + goodNodesHelper(root->left, currentMax) + goodNodesHelper(root->right, currentMax);
		}
		else {
			return  goodNodesHelper(root->left, currentMax) + goodNodesHelper(root->right, currentMax);
		}
	}
   */
   /*
   	int goodNodes(TreeNode* root){
		int count = 0;
		goodNodesHelper(root,root->val,count);
		return count;
	}

	int goodNodesHelper(TreeNode* root, int prevMax,int& count){
		if(root == NULL){
			return 0;
		}

		if(root->val >= prevMax){
            count++;
            prevMax = root->val;
        }
		
		return  goodNodesHelper(root->left, prevMax,count) + goodNodesHelper(root->right, prevMax,count);
	}
    */
  int goodNodes(TreeNode* root){
		if(!root)
            return 0;
	    return goodNodes(root,root->val);
		
	}
    int goodNodes(TreeNode* root, int maxSoFar){
		if(!root){
			return 0;
		}

        int addme = root->val >= maxSoFar;
        int l = goodNodes(root->left, max(maxSoFar, root->val));
        int r = goodNodes(root->right, max(maxSoFar, root->val));  
        return addme + l + r;
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
	TreeNode* root = newnode(5);
	root->left = newnode(4);
	root->right = newnode(6);

	root->left->left = newnode(3);
	root->left->right = newnode(8);

	Solution s;
	cout << s.goodNodes(root);
	return 0;
}
