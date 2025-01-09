#include "../common.h"

//https://leetcode.com/problems/remove-linked-list-elements/
 class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) {
            return NULL;
        }

        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode* current_Node = dummyHead;

        while (current_Node->next != NULL) {
            if (current_Node->next->val == val) {
                ListNode* tmp = current_Node->next;
                current_Node->next = current_Node->next->next;
                delete tmp;
                
            } else {
                current_Node = current_Node->next;
            }
        }

        return dummyHead->next;
    }
};




int main()
{
	ListNode* head = createDummyList();
	Solution s;
	ListNode* newHead = s.removeElements(head,2);
	printList(newHead);

	delete head;
	delete newHead;
	
	return 0;
}