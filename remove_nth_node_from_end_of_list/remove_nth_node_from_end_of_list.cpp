#include "../common.h"

ListNode *createDummyList();
void printList(ListNode *head);
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/
class Solution
{
public:
	ListNode *removeNthFromEnd(ListNode *head, int n)
	{
		if (n == 1 && head->next == nullptr)
			return nullptr;

		ListNode *dummyNode = new ListNode(INT_MAX, head);
		ListNode *slowPtr = dummyNode;
		ListNode *fastPtr = head;

		while (n != 0)
		{
			fastPtr = fastPtr->next;
			--n;
		}

		while (fastPtr != nullptr)
		{
			slowPtr = slowPtr->next;
			fastPtr = fastPtr->next;
		}

		slowPtr->next = slowPtr->next->next;

		return dummyNode->next;
	}
};

int main()
{
	ListNode *head = createDummyList();
	printList(head);

	ListNode *head2 = createDummyList();

	Solution s;
	ListNode *result = s.removeNthFromEnd(head2, 1);
	printList(result);

	return 0;
}

ListNode *createDummyList()
{
	ListNode *n6 = new ListNode(6);
	ListNode *n5 = new ListNode(5);
	n5->next = n6;
	ListNode *n4 = new ListNode(4);
	n4->next = n5;
	ListNode *n3 = new ListNode(3);
	n3->next = n4;
	ListNode *n2 = new ListNode(2);
	n2->next = n3;
	ListNode *n1 = new ListNode(1);
	n1->next = n2;

	return n1;
}

void printList(ListNode *head)
{
	while (head != nullptr)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}