#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
private:
    vector<int> nodesPerLevel;

public:
    Node *connect(Node *root)
    {
        if (root == nullptr)
            return nullptr;

        Node *rootPtr = root;
        stack<Node *> stkLinker;
        queue<Node *> myQueue;

        nodesPerLevel.push_back(1);
        int index = 0;

        myQueue.push(rootPtr);

        while (!myQueue.empty())
        {
            if (index == 0)
            {
                Node *myRoot = myQueue.front();
                myRoot->next = nullptr;
                int nodesInNextLevel = 0;
                if (myRoot->left)
                {
                    myQueue.push(myRoot->left);
                    nodesInNextLevel++;
                    stkLinker.push(myRoot->left);
                }
                if (myRoot->right)
                {
                    myQueue.push(myRoot->right);
                    nodesInNextLevel++;
                    stkLinker.push(myRoot->right);
                }
                index++;
                myQueue.pop();
                nodesPerLevel.push_back(nodesInNextLevel);
            }
            else
            {
                Node *ptrNextNode = nullptr;
                // update nodes next references...
                while (!stkLinker.empty())
                {
                    Node *topNode = stkLinker.top();
                    stkLinker.pop();
                    topNode->next = ptrNextNode;
                    ptrNextNode = topNode;
                }

                int nodesToRemove = nodesPerLevel[index];
                // scan the nodes in the level and add them to the queue, stack for next feed.
                int nodesInNextLevel = 0;
                while (nodesToRemove--)
                {

                    Node *levlNode = myQueue.front();

                    if (levlNode->left)
                    {
                        myQueue.push(levlNode->left);
                        nodesInNextLevel++;
                        stkLinker.push(levlNode->left);
                    }
                    if (levlNode->right)
                    {
                        myQueue.push(levlNode->right);
                        nodesInNextLevel++;
                        stkLinker.push(levlNode->right);
                    }

                    myQueue.pop();
                }
                nodesPerLevel.push_back(nodesInNextLevel);
                index++;
            }
        }
        return rootPtr;
    }
};

int main()
{
    Node *n7 = new Node(7);
    Node *n6 = new Node(6);
    Node *n5 = new Node(5);
    Node *n4 = new Node(4);
    Node *n3 = new Node(3);
    Node *n2 = new Node(2);
    Node *root = new Node(1);

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
