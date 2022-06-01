#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
//TODO: Write the algo.
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
private:
    int level = 1;
public:
    Node* connect(Node* root) {
        if (level == 1)
        {
            root->next = nullptr;
            level++;
            
            queue<Node*> nodesNextLevel;
            
            if (root->left != nullptr)
                nodesNextLevel.push(root->left);
            if (root->right != nullptr)
                nodesNextLevel.push(root->right);

            Node* leftOne = nullptr;
            Node* rightOne = nullptr;

            while (nodesNextLevel.size() > 0)
            {
                leftOne = nodesNextLevel.front();
                nodesNextLevel.pop();
                rightOne = nodesNextLevel.front();
                nodesNextLevel.pop();
                leftOne->next = rightOne;
            }

            rightOne->next = nullptr;

        }
        else
        {

        }
    }

    vector<Node*> getNeighbour(Node* root) {

    }

};

int main()
{
    Node* n7 = new Node(7);
    Node* n6 = new Node(6);
    Node* n5 = new Node(5);
    Node* n4 = new Node(4);
    Node* n3 = new Node(3);
    Node* n2 = new Node(2);
    Node* root = new Node(1);
    
    root->left = n2;
    root->right = n3;
    
    n2->left = n4;
    n2->right = n5;


    n3->left = n6;
    n3->right = n7;

    Solution s;
    s.connect(root);


    return 0;
}
