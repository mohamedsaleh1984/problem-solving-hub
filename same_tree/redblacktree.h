#ifndef __redblacktree_h__
#define __redblacktree_h__
#include "common.h"

class RedBlackTree;

class rbNode {
public:
    int data;
    bool color;
    rbNode* left, * right, * parent;

    rbNode(int data) {
        this->data = data;
        left = right = parent = nullptr;
        this->color = RED;
    }
};

class RedBlackTree {
private:
    rbNode* root;
protected:
    void rotateLeft(rbNode*& root, rbNode*& pt) {
        rbNode* pt_right = pt->right;

        pt->right = pt_right->left;

        if (pt->right != nullptr)
            pt->right->parent = pt;

        pt_right->parent = pt->parent;

        if (pt->parent == nullptr)
            root = pt_right;

        else if (pt == pt->parent->left)
            pt->parent->left = pt_right;

        else
            pt->parent->right = pt_right;

        pt_right->left = pt;
        pt->parent = pt_right;
    }

    void rotateRight(rbNode*& root, rbNode*& pt) {
        rbNode* pt_left = pt->left;

        pt->left = pt_left->right;

        if (pt->left != nullptr)
            pt->left->parent = pt;

        pt_left->parent = pt->parent;

        if (pt->parent == nullptr)
            root = pt_left;

        else if (pt == pt->parent->left)
            pt->parent->left = pt_left;

        else
            pt->parent->right = pt_left;

        pt_left->right = pt;
        pt->parent = pt_left;
    }

    void fixViolation(rbNode*& root, rbNode*& pt) {
        rbNode* parent_pt = nullptr;
        rbNode* grand_parent_pt = nullptr;

        while ((pt != root) && (pt->color != BLACK) &&
               (pt->parent->color == RED)) {

            parent_pt = pt->parent;
            grand_parent_pt = pt->parent->parent;

            /* Case A: Parent of pt is left child of Grand-parent of pt */
            if (parent_pt == grand_parent_pt->left) {

                rbNode* uncle_pt = grand_parent_pt->right;

                /* Case 1: The uncle of pt is also red
                   Only Recoloring required */
                if (uncle_pt != nullptr && uncle_pt->color == RED) {
                    grand_parent_pt->color = RED;
                    parent_pt->color = BLACK;
                    uncle_pt->color = BLACK;
                    pt = grand_parent_pt;
                }

                else {
                    /* Case 2: pt is right child of its parent
                       Left-rotation required */
                    if (pt == parent_pt->right) {
                        rotateLeft(root, parent_pt);
                        pt = parent_pt;
                        parent_pt = pt->parent;
                    }

                    /* Case 3: pt is left child of its parent
                       Right-rotation required */
                    rotateRight(root, grand_parent_pt);
                    swap(parent_pt->color, grand_parent_pt->color);
                    pt = parent_pt;
                }
            }

            /* Case B: Parent of pt is right child of Grand-parent of pt */
            else {
                rbNode* uncle_pt = grand_parent_pt->left;

                /* Case 1: The uncle of pt is also red
                   Only Recoloring required */
                if ((uncle_pt != nullptr) && (uncle_pt->color == RED)) {
                    grand_parent_pt->color = RED;
                    parent_pt->color = BLACK;
                    uncle_pt->color = BLACK;
                    pt = grand_parent_pt;
                }
                else {
                    /* Case 2: pt is left child of its parent
                       Right-rotation required */
                    if (pt == parent_pt->left) {
                        rotateRight(root, parent_pt);
                        pt = parent_pt;
                        parent_pt = pt->parent;
                    }

                    /* Case 3: pt is right child of its parent
                       Left-rotation required */
                    rotateLeft(root, grand_parent_pt);
                    swap(parent_pt->color, grand_parent_pt->color);
                    pt = parent_pt;
                }
            }
        }

        root->color = BLACK;
    }

public:
    RedBlackTree() { root = nullptr; }

    void insert(const int& data) {
        rbNode* pt = new rbNode(data);

        root = BSTInsert(root, pt);

        fixViolation(root, pt);
    }

    void inorder() { inorderHelper(root); }

private:
    void inorderHelper(rbNode* root) {
        if (root == nullptr)
            return;

        inorderHelper(root->left);
        cout << root->data << " ";
        inorderHelper(root->right);
    }

    rbNode* BSTInsert(rbNode* root, rbNode* pt) {
        if (root == nullptr)
            return pt;

        if (pt->data < root->data) {
            root->left = BSTInsert(root->left, pt);
            root->left->parent = root;
        }
        else if (pt->data > root->data) {
            root->right = BSTInsert(root->right, pt);
            root->right->parent = root;
        }

        return root;
    }
};

 


#endif