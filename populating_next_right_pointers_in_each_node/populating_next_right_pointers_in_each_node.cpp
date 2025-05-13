#include "../common.h"

//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
 

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return nullptr;

        Node* rootPtr = root;
        stack<Node*> stkLinker;
        queue<Node*> myQueue;

        int powInd = 0;
        int nodesToRemove = pow(2, powInd);
        myQueue.push(rootPtr);

        while (!myQueue.empty()) {
            if (nodesToRemove == 1) {
                Node* myRoot = myQueue.front();
                myRoot->next = nullptr;
                if (myRoot->left) {
                    myQueue.push(myRoot->left);
                    myQueue.push(myRoot->right);

                    stkLinker.push(myRoot->left);
                    stkLinker.push(myRoot->right);
                }
                myQueue.pop();
            }
            else
            {
                Node* ptrNextNode = nullptr;
                //update nodes next references...
                while (!stkLinker.empty())
                {
                    Node* topNode = stkLinker.top();
                    stkLinker.pop();
                    topNode->next = ptrNextNode;
                    ptrNextNode = topNode;
                }
                //scan the nodes in the level and add them to the queue, stack for next feed.
                while (nodesToRemove--) {
                   Node* levlNode = myQueue.front();

                   if (levlNode->left) {
                       myQueue.push(levlNode->left);
                       myQueue.push(levlNode->right);

                       stkLinker.push(levlNode->left);
                       stkLinker.push(levlNode->right);
                   }
                   myQueue.pop();
                }
            }

            powInd++;
            nodesToRemove = pow(2, powInd);
        }
        return rootPtr;
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
