#include <iostream>
#include <list>
using namespace std;
#include "GPOE.h"
void inOrder(struct treeNode* r);

//#TODO: Split all this code into separate projects.
struct treeNode
{
	struct treeNode* left;
	struct treeNode* right;
	int data;
	treeNode(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}
};
treeNode* deleteFromBST(struct treeNode* root, int dataToRemove);
struct treeNode* insert(struct treeNode* node, int key);
struct treeNode* lowestCommonAncestor(struct treeNode* root, struct treeNode* node1, struct treeNode* node2);
bool IsSorted(vector<int> vec);
void dumpInOrder(struct treeNode* root, vector<int>& vec);
int sum(string str, int size);
unsigned long sumOfString(string str, int size, unsigned long sum);
void repeatNtimes(string& str, int num, int n);
int andXorOr(vector<int> a);

bool isPalindromic(vector<int> vec) {
	if (vec.size() == 0 || vec.size() == 1)
		return true;

	bool bResult = true;
	int start = 0, end = vec.size() - 1;
	while (start != end) {
		if (vec[start] != vec[end]) {
			bResult = false;
			break;
		}
		else
		{
			start++;
			end--;
		}
	}

	return bResult;
}
bool IsLikedListPalindromic(std::list<int> ls) {
	if (ls.size() == 0 || ls.size() == 1)
		return true;

	vector<int> vec;
	
	for (std::list<int>::iterator it = ls.begin(); it != ls.end(); ++it)
		vec.push_back(*it);

	return isPalindromic(vec);
}



int main()
{
	std::list<int> mylist{1,2,1};
	

	cout << IsLikedListPalindromic(mylist) << endl;


	int i = 0;
	cin >> i;

	/*
	string s = "148";
	int sum = 0;
	int len = s.size();
	StringSum(s, ref(sum), len);
	cout << sum << endl;
	*/

	/*
	struct Node* ll = new Node(10);
	ll->next = new Node(20);
	ll->next->next = new Node(30); 
	ll->next->next->next = new Node(40);
	ll->next->next->next->next = new Node(50);

	traverse(ll);
	cout << "\n";
	//Delete(ll, 40);
	//traverse(ll);
	cout << "\n";
	vector<int> vec{ 1,-2,3,10,-8,0 };
	cout << RangeSum(vec, 1, 3);*/

	/*
	struct treeNode* root = new treeNode(46);
	root->left = new treeNode(24);
	root->right = new treeNode(49);
	root->left->left = new treeNode(22);
	root->left->right = new treeNode(26);
	root->left->right->right = new treeNode(30);
	root->right->right = new treeNode(90);
	root->right->left = new treeNode(47);
	root->right->right->left = new treeNode(80);

	cout << IsBST(root) << endl;
	*/
	//cout << lowestCommonAncestor(root, root->left, root->left->left)->data << endl;
	return 0;
}

void inOrder(struct treeNode* r)
{
	if (r == NULL)
		return;
	inOrder(r->left);
	cout << r->data << " ";
	inOrder(r->right);
}

treeNode* deleteFromBST(struct treeNode* root, int dataToRemove) {
	if (root == nullptr)
		return root;
	else if (dataToRemove < root->data)
		root->left = deleteFromBST(root->left, dataToRemove);
	else if (dataToRemove > root->data)
		root->right = deleteFromBST(root->right, dataToRemove);
	else //Data To Delete == ROOT
	{
		//Check the NODE Status
		//1. Leaf node 
		if (root->left == nullptr && root->right == nullptr) {
			free(root);
			root = nullptr;
		}
		else if (root->left == nullptr && root->right != nullptr) {
			treeNode* temp = root;
			root = root->right;
			free(temp);
		}
		else if (root->right == nullptr && root->left != nullptr) {
			treeNode* temp = root;
			root = root->left;
			free(temp);
		}
		else if (root->right != nullptr && root->left != nullptr) {
			treeNode* temp = root->right;
			while (temp->left != nullptr) temp = temp->left;
			root->data = temp->data;
			root->right = deleteFromBST(root->right, temp->data);
		}
	}
	return root;
}
struct treeNode* insert(struct treeNode* node, int key)
{
	/* If the tree is empty, return a new node */
	if (node == NULL)
		return new treeNode(key);

	/* Otherwise, recur down the tree */
	if (key < node->data)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

	/* return the (unchanged) node pointer */
	return node;
}

struct treeNode* lowestCommonAncestor(struct treeNode* root, struct treeNode* node1, struct treeNode* node2) {
	if (root == NULL)
		return NULL;
	else if (node1->data == root->data || node2->data == root->data)
		return root;
	else if ((node1->data <= root->data && node2->data > root->data)
		|| (node2->data <= root->data && node1->data > root->data)) {
		return root;
	}
	else if (root->data > max(node1->data, node2->data)) {
		return lowestCommonAncestor(root->left, node1, node2);
	}
	else {
		return lowestCommonAncestor(root->right, node1, node2);
	}
}


void dumpInOrder(struct treeNode* root, vector<int>& vec) {
	if (root == nullptr)
		return;
	dumpInOrder(root->left, vec);
	vec.push_back(root->data);
	dumpInOrder(root->right, vec);
}

bool IsBST(struct treeNode* root) {
	vector<int> vec = {};
	dumpInOrder(root, vec);
	return IsSorted(vec);
}

bool IsSorted(vector<int> vec) {
	if (vec.size())
		return true;

	int elem = vec[0];
	for (int i = 1; i < vec.size(); i++)
		if (elem > vec[i])
			return false;
		else
			elem = vec[i];
	return true;
}

double RangeSum(vector<int> arr, int i, int j)
{
	vector<int> vecSums(arr.size(), 0);
	vecSums[0] = (arr[0]);
	//Compute the Icremental Sum of the List
	for (size_t i = 1, j = 0; i < arr.size(); i++, j++)
		vecSums[i] = vecSums[j] + arr[i];

	if (i == 0)
		return vecSums[j];
	//J element minus i elment which is the sum from i to j
	return vecSums[j] - vecSums[i - 1];
}

void StringSum(std::string strInput, int& sum, int len) {

	if (sum <= 9 && len == 0)
		return;

	if (len == 0 && sum > 0)
	{
		std::string convertedNewSum = std::to_string(sum);
		sum = 0;
		StringSum(convertedNewSum, sum, convertedNewSum.length());
	}
	else
	{
		sum += (int)(strInput[len - 1] - 48);
		StringSum(strInput.substr(0, len - 1), sum, len - 1);
	}
}

struct Node {
	int data;
	Node* next;
	Node(int d) {
		data = d;
		next = NULL;
	}
};

void Delete(struct Node* root, int data) {
	struct Node* pre = NULL;

	while (root != NULL) {
		pre = root;
		root = root->next;
		if (root->data == data) {
			break;
		}
	}

	cout << "Pre " << pre->data << endl;
	pre = pre->next->next;
}


void traverse(struct Node* root) {
	while (root != NULL) {
		cout << root->data << " ";
		root = root->next;
	}
}


int andXorOr(vector<int> a) {
	int m1, m2;
	int L = 1, R = 2;
	std::vector<int>::iterator result = std::min_element(a.begin(), a.begin() + 2);
	m1 = *result;
	a[result - a.begin()] = INT_MAX;
	result = std::min_element(a.begin(), a.begin() + 2);
	m2 = *result;
	return ((m2 & m1) ^ (m2 | m1) & (m1 ^ m2));
}
