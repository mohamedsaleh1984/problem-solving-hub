#include <iostream>
#include <vector>
using namespace std;
// https://leetcode.com/problems/leaf-similar-trees/submissions/1473328293/?envType=study-plan-v2&envId=leetcode-75
// 0ms Beats 100.00%
// 08/12/2024

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void leafs(TreeNode* root, vector<int>& ns){
        if(root == nullptr)
            return;
        
        leafs(root->left,ns);
        
        if(root->left == nullptr && root->right == nullptr)
            ns.push_back(root->val);
        
        leafs(root->right,ns);
    }


    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> vec1; leafs(root1,vec1);
        vector<int> vec2; leafs(root2,vec2);
        
        return vec1 == vec2;
    }
};



int main(int argc, char** argv)
{
	

	return 0;
}
