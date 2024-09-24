// Linked List Cycle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

  struct ListNode {
     int val;
     ListNode* next;
     ListNode(int x) : val(x), next(NULL) {}
    
};
  //https://leetcode.com/problems/linked-list-cycle/
  //TODO: Fix for single node;
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr)
            return false;


        ListNode* slow = head;
        ListNode* fast = head->next;

        while (slow != nullptr && fast->next != nullptr) {
            if (slow == fast)
                return true;

            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};
int main()
{
    std::cout << "Hello World!\n";
}
