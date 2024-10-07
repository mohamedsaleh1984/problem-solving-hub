#ifndef __binary_tree_h__
#define __binary_tree_h__
#include "common.h"

class BinaryTree;

// Definition for a binary tree node
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor to create a new node
    TreeNode(int value) {
        val = value;
        left = right = nullptr;
    }
};


// Binary Tree class to perform various operations
class BinaryTree {
public:
    TreeNode* root;

    // Constructor to create an empty tree
    BinaryTree() {
        root = nullptr;
    }

    // Insertion
    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->val) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }

        return node;
    }

    // Searching
    bool search(TreeNode* node, int key) {
        if (node == nullptr) {
            return false;
        }
        if (node->val == key) {
            return true;
        }
        if (key < node->val) {
            return search(node->left, key);
        } else {
            return search(node->right, key);
        }
    }

    // In-Order Traversal (Left, Root, Right)
    void inorder(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
    }

    // Pre-Order Traversal (Root, Left, Right)
    void preorder(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        cout << node->val << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // Post-Order Traversal (Left, Right, Root)
    void postorder(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        postorder(node->left);
        postorder(node->right);
        cout << node->val << " ";
    }

    // Find the minimum value in the tree
    TreeNode* findMin(TreeNode* node) {
        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Deletion
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Node with only one child or no child
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children: Get the inorder successor
            TreeNode* temp = findMin(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }
};


#endif