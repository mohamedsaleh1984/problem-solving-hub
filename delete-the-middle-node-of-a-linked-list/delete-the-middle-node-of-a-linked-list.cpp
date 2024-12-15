#include "../common.h"


// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/?envType=study-plan-v2&envId=leetcode-75
// 12/15/2024
// 0 msBeats 100.00%

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == nullptr){
            return nullptr;
        }

        ListNode* tmpHead =  head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* beforeSlow = head;

        while(fast && fast->next){
            beforeSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // get to the middle
        beforeSlow->next =  slow->next;
        return tmpHead;
    }
};

int main(int argc,char** argv){


    return 0;
}