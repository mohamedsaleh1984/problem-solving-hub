#include "../common.h"

ListNode* removeNthFromEnd(ListNode* head, int n) {
	if (n == 1 && head->next == nullptr)
		return nullptr;
	if (n == 1 && head->next != nullptr)
		return head->next;


	int counter = 1;
	ListNode* headCpy = head;
	ListNode* nodeModifier = head;
	ListNode* prevNode = head;

	while (nodeModifier != nullptr)
	{
		if (counter == n)
		{
			prevNode->next = nodeModifier->next;
			break;
		}
		prevNode = nodeModifier;
		nodeModifier = nodeModifier->next;
		counter++;
	}
	return headCpy;
}
 
int main()
{
	ListNode* head = createDummyList();
	cout << "----------- before Remove nth elem -----------------\n";
	printList(head);

	ListNode* head2 = createDummyList();

	ListNode* result = removeNthFromEnd(head2, 2);
	cout << "\n----------- after Remove nth elem -----------------\n";
	printList(result);

	return 0;
}
