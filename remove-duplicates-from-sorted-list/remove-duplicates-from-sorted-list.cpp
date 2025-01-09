#include "../common.h"

// https://leetcode.com/problems/remove-duplicates-from-sorted-list/submissions/1445394019/
// 0 ms Beats 100.00%

class Solution
{
public:
    void printout(ListNode *head)
    {
        while (head)
        {
            cout << head->val << " ";
            head = head->next;
        }
    }

    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *ptrHead = head;
        while (ptrHead != nullptr)
        {
            int current = ptrHead->val;

            if (ptrHead->next != nullptr)
            {
                int next = ptrHead->next->val;
                if (current == next)
                {
                    ListNode *refNext = ptrHead->next;
                    // Move forward
                    ptrHead->next = ptrHead->next->next;
                    // Delete Middle node
                    delete refNext;
                }
                else
                {
                    ptrHead = ptrHead->next;
                }
            }
            else
            {
                ptrHead = ptrHead->next;
            }
        }

        return head;
    }
};

int main(void)
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(1);
    // head->next->next->next->next = new ListNode(3);

    Solution s;
    ListNode *newHead = s.deleteDuplicates(head);
    s.printout(newHead);

    return 0;
}
