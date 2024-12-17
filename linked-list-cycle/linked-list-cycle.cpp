#include "../common.h"
  //https://leetcode.com/problems/linked-list-cycle/
  // 12/15/2024
  // 15ms Beats 12.25%
 
class Solution {
public:
    // O(1) using fast and slow pointer
    bool hasCycle(ListNode* head) {
        if (head == nullptr)
            return false;
        if (head->next == nullptr) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
    }
    // O(N) using sets
    bool hasCycle2(ListNode* head) {
        if (head == nullptr)
            return false;
        set<ListNode*> nodes;
        ListNode* tmp = head;
        while (tmp) {
            if (nodes.count(tmp)) {
                return true;
            } else {
                nodes.insert(tmp);
            }

            tmp = tmp->next;
        }

        return false;
    }
};

int main()
{
    
    return 0;
}
