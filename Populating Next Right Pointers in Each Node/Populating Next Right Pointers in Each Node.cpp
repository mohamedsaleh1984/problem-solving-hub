// Populating Next Right Pointers in Each Node.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {

    }
};
int main()
{
    std::cout << "Hello World!\n";
}
