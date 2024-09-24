#include <iostream>
using namespace std;

  struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//https://leetcode.com/problems/reverse-linked-list/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;

        while (head != nullptr)
        {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            if (next == nullptr)break;
            head = next;
        }
        return head;
    }
};


void traverse(ListNode* root) {
    while (root) {
        cout << root->val << " ";
        root = root->next;
    }
    cout << endl;
}

int main()
{
    ListNode* n6 = new ListNode(6);
    ListNode* n5 = new ListNode(5);
    n5->next = n6;
    ListNode* n4 = new ListNode(4);
    n4->next = n5;
    ListNode* n3 = new ListNode(3);
    n3->next = n4;
    ListNode* n2 = new ListNode(2);
    n2->next = n3;
    ListNode* n1 = new ListNode(1);
    n1->next = n2;

    Solution s;
    traverse(n1);
    ListNode* result=  s.reverseList(n1);
    traverse(result);
    return 0;
}
