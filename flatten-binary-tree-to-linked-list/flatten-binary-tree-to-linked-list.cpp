#include "../common.h"

class Solution {
    queue<TreeNode*> Q;

public:
    void flatten(TreeNode* root) {
        /*
            1. Find the right most node on the left subtree
            2. place the right subtree on the side
            3. repeate
        */
        TreeNode* current = root;

        while(current != nullptr){
            if(current->left != nullptr){
                TreeNode* temp = current->left;
                while(temp->right != nullptr) {
                    temp = temp->right;
                }

                temp->right = current->right;
                current->right = current->left;
                current->left = nullptr;
            }
            current = current->right;
        }
    }
    void flatten2(TreeNode* root) {
        storeNodes(root);

        TreeNode* newRoot = new TreeNode(0);
        newRoot->left = nullptr;
        newRoot->right = nullptr;
        TreeNode* tmp = newRoot;
        while (!Q.empty()) {

            TreeNode* sNode = Q.front();
            cout << "sss " << sNode->val << endl;

            tmp->right = new TreeNode(sNode->val);
            tmp->left = nullptr;

            tmp = tmp->right;
            Q.pop();
        }
        root = newRoot->right;
        // return newRoot->right;
    }
    void storeNodes(TreeNode* root) {
        if (root == nullptr)
            return;
        Q.push(root);
        storeNodes(root->left);
        storeNodes(root->right);
    }
};

int main()
{
 
    return 0;
}