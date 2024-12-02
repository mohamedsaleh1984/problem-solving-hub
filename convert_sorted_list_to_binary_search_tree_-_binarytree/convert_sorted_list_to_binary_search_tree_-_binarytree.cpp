
//#TODO : Fix LinkedList Algo
#include <iostream>
#include <vector>
using namespace std;

 struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};
 struct TreeNode {
     int val;
     TreeNode* left;
     TreeNode* right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
     
 };

 TreeNode* creatBST(vector<int> arr, int L, int R) {
     if (R < L) {
         return NULL;
     }

     int min = (L + R) / 2;
     TreeNode* root = new TreeNode(arr[min]);
     root->left = creatBST(arr, L, min - 1);
     root->right = creatBST(arr, min + 1, R);

     return root;
 }

TreeNode* sortedListToBST(ListNode* head) {
    vector<int> vec;
    while (head != NULL) {
        vec.push_back(head->val);
        head = head->next;
    }

    TreeNode* root = creatBST(vec, 0, vec.size() - 1);
    return root;
}

ListNode* createLinkedListVector(vector<int> vec) {
    if (vec.size() == 0)
        return NULL;
    ListNode* head = NULL;
    ListNode* temp = head;

    for(int item:vec)
    {
        temp = new ListNode(item);
        temp = temp->next;
    }
    return head;
}



void InOrder(TreeNode* root) {
    if (root == NULL)
        return;
    InOrder(root->left);
    cout << root->val << " ";
    InOrder(root->right);
}

int main()
{
    vector<int> lst = { -10,-3,0,5,9 };
    ListNode* ll = createLinkedListVector(lst);
    TreeNode* root = sortedListToBST(ll);
    InOrder(root);
    return 0;
}
