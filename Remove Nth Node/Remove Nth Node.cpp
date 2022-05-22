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


ListNode* createDummyList() {
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

	return n1;
}

void printList(ListNode* head) {
	while (head != nullptr)
	{
		cout << head->val << " ";
		head = head->next;
	}
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
