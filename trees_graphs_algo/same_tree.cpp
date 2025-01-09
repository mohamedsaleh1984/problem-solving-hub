
#include "common.h"
#include "binary_tree.h"
#include "avl_tree.h"
#include "bfs.h"
#include "dfs.h"
#include "dijkstra.h"
#include "prime.h"
#include "kruskal.h"
#include "redblacktree.h"

using namespace std;

class Solution
{
public:
    bool isSameTreex(TreeNode* p, TreeNode* q) {
        string pTree,qTree;
        inOrder(p,pTree);
        inOrder(q,qTree);
        return pTree==qTree;
    }
    void inOrder(TreeNode* p,string& s){
        if(p == nullptr)   
            return;
        inOrder(p->left,s);
        s+=to_string(p->val);
        inOrder(p->right,s);
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q != nullptr)
            return false;

        if (p != nullptr && q == nullptr)
            return false;

        if (p == nullptr && q == nullptr)
            return true;

        if (p->val == q->val)
        {
            bool left = isSameTree(p->left, q->left);

            bool right = isSameTree(p->right, q->right);
            return left && right;
        }

        return false;
    }
};

void avl()
{
    AVLTree avl;
    avl.root = avl.insert(avl.root, 10);
    avl.insert(avl.root, 20);
    avl.insert(avl.root, 5);
    avl.insert(avl.root, 4);
    avl.insert(avl.root, 6);

    avl.inorder(avl.root);
}

void bst()
{
    BinaryTree tree;

    // Insert nodes
    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    // Traversals
    cout << "Inorder traversal: ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "Preorder traversal: ";
    tree.preorder(tree.root);
    cout << endl;

    cout << "Postorder traversal: ";
    tree.postorder(tree.root);
    cout << endl;

    // Search for a node
    int key = 40;
    if (tree.search(tree.root, key))
    {
        cout << "Node " << key << " found in the tree." << endl;
    }
    else
    {
        cout << "Node " << key << " not found in the tree." << endl;
    }

    // Deletion
    cout << "Deleting node 20" << endl;
    tree.deleteNode(tree.root, 20);
    cout << "Inorder traversal after deletion: ";
    tree.inorder(tree.root);
    cout << endl;
}

void bfs()
{
    bfs_Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "BFS starting from node 2:" << endl;
    g.BFS(2);
}

void dfs(){
    dfs_Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "DFS starting from node 2:" << endl;
    g.DFS(2);
}

void dijkstra(){

    DGraph g(9);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.dijkstra(0);

}

void prime(){
    prime_Graph g(9);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.primMST();
}

void kruskal(){
     krus_Graph g(4, 5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    g.kruskalMST();
}

void redblackTree(){
      RedBlackTree tree;

    tree.insert(7);
    tree.insert(3);
    tree.insert(18);
    tree.insert(10);
    tree.insert(22);
    tree.insert(8);
    tree.insert(11);
    tree.insert(26);
    tree.insert(2);
    tree.insert(6);
    tree.insert(13);

    cout << "Inorder Traversal of the Red-Black Tree: ";
    tree.inorder();
}

int main()
{
    BinaryTree p;
    p.root = p.insert(p.root, 50);
    p.insert(p.root, 30);
    p.insert(p.root, 20);
    p.insert(p.root, 40);
    p.insert(p.root, 70);
 

    BinaryTree q;
    q.root = q.insert(q.root, 50);
    q.insert(q.root, 30);
    q.insert(q.root, 20);
    q.insert(q.root, 40);
    q.insert(q.root, 70);
    q.insert(q.root, 60);
    q.insert(q.root, 80);

    
    Solution s;
    cout << s.isSameTree(p.root,q.root) << endl;

    return 0;
}