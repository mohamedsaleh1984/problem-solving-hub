#include "../common.h"

struct TreeNode* newNode(int data);


vector< vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    vector<int> root_vec = {};

    if (root == nullptr) {
        return result;
    }

    root_vec.push_back(root->val);
    result.push_back(root_vec);

	stack<TreeNode*> Q;
	Q.push(root);


	while (!Q.empty()) {
		vector<int> level;

		TreeNode* node = Q.top();	
		if (node->left){
			level.push_back(node->left->val);
		}
			
		if (node->right) {
			level.push_back(node->right->val);
		}
		Q.pop();

		result.push_back(level);


	}

    return result;
}


int main()
{
	struct TreeNode* root = newNode(3);
	root->left = newNode(9);
	root->right = newNode(20);
	root->left->left = nullptr;
	root->left->right = nullptr;
	root->right->right = newNode(7);
	root->right->left = newNode(15);
	vector< vector<int>> res = levelOrder(root);

	return 0;
}
 
