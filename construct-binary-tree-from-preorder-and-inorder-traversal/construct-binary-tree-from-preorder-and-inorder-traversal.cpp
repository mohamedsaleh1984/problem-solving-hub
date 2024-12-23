#include "../common.h"

// 
class Solution {
public:
    TreeNode* buildBST(vector<int> nodes){
        int left = 0;
        int right = nodes.size();
        TreeNode*  root = buildBSTHelper(nodes,0, right);
        return root;
    }
    TreeNode* buildBSTHelper(vector<int> nodes, int left, int right){
        if(left > right){
            return NULL;
        }

        int midIndex = (left+right)/2;
        
        TreeNode* root = new TreeNode(nodes[midIndex]);
        
        root->left = buildBSTHelper(nodes,left,midIndex-1);
        root->right = buildBSTHelper(nodes,midIndex+1, right);
        
        return root; 
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        int rootIndex = findRootIndex(inorder,preorder[0]);
        
        vector<int> leftSide ;
        vector<int> rightSide;
        
        copy(inorder.begin()+0, inorder.begin()+rootIndex, back_inserter(leftSide));
        copy(inorder.begin()+rootIndex+1, inorder.end(), back_inserter(rightSide));

        root->left = buildBSTHelper(leftSide,0, leftSide.size());
        root->right = buildBSTHelper(rightSide,0, rightSide.size());
        
        return root;
    }

    int findRootIndex(vector<int> inorder, int rootValue){
        for(int i = 0 ; i < inorder.size() ; i++){
            if(rootValue == inorder[i]){
                return i;
            }
        }
        return -1;
    }
};

int main(int argc, char** argv){

    vector<int> pre = {3,9,20,15,7};
    vector<int> ino = {9,3,15,20,7};
    
    Solution s;
    TreeNode* root = s.buildTree(pre,ino);

    inorder(root);


    return 0;
}