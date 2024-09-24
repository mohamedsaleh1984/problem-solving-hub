#include <iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
};

class Solution {
public:
		//decrease the value and check left/right trees.
		bool hasPathSum(TreeNode* root, int targetSum) {
			if (root == NULL)
				return false;

			targetSum = targetSum - root->val;

			if (root->left == NULL && root->right == NULL && targetSum == 0)
				return true;

			bool leftSubTree = hasPathSum(root->left, targetSum);
			bool rightSubTree = hasPathSum(root->right, targetSum);
			return leftSubTree || rightSubTree;
		}
 };


struct TreeNode* newNode(int data)
{
	struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->val = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

int main()
{
	/*struct TreeNode* t1 = newNode(5);
	t1->left = newNode(4);
	t1->right = newNode(8);
	t1->right->left = newNode(13);
	t1->left->left = newNode(11);
	t1->right->right = newNode(4);
	t1->right->right->right = newNode(1);
	t1->left->left->left = newNode(7);
	t1->left->left->right = newNode(2);*/


	/*struct TreeNode* t2 = newNode(1);
	t2->left = newNode(2);
	 */

	/*struct TreeNode* t3 = newNode(1);
	t3->left = newNode(2);
	t3->right = newNode(3);*/

	struct TreeNode* t4 = newNode(1);
	t4->left = newNode(2); 
	
	Solution s;
	printf("has Path Sum %d \n", s.hasPathSum(t4,1));

	return 0;	
}
