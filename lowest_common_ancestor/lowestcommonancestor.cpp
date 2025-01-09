#include "../common.h"

class Node {
public:
	Node(int val) {
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
	Node* left;
	Node* right;
	int getDate() {
		return this->val;
	}
private:
	int val;
};


Node* lca(Node* root, int v1, int v2) {
	if (root == NULL)
		return NULL;

	if (root->getDate() == v1 || root->getDate() == v2)
		return root;

	Node* llca = lca(root->left, v1, v2);
	Node* rlca = lca(root->right, v1, v2);

	if (llca && rlca)
		return root;

	return llca ? llca : rlca;
}


void inOrder(Node* root) {
	if (root == NULL)
		return;
	inOrder(root->left);
	cout << root->getDate() << " ";
	inOrder(root->right);
}

int main()
{
	Node* root = new Node(10);
	root->left = new Node(12);
	root->left->left = new Node(89);
	root->left->right = new Node(-1);
	root->left->right->left = new Node(72);
	root->right= new Node(15);

	inOrder(root);


	cout << "\n";

	Node* node = lca(root, 15, 72);
	cout << "Lowest Common Ancestor :: " << node->getDate() << endl;




	return 0;
}
 