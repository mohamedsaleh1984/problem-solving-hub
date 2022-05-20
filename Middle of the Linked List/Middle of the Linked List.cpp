#include <iostream>
using namespace std;

//https://leetcode.com/problems/middle-of-the-linked-list/

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* middleNode(ListNode* head) {
	ListNode* slow = head;
	if (slow->next == nullptr)
		return slow;

	if (slow->next->next == nullptr)
		return slow->next;
	
	ListNode* fast = slow->next->next;

	while (fast != nullptr) {
		if (fast->next != nullptr && fast->next->next != nullptr)
			fast = fast->next->next;
		else
			fast = fast->next;
		slow = slow->next;
	}

	return slow;
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

	ListNode* test = n1;
	while (test != nullptr)
	{
		cout << test->val << " ";
		test = test->next;
	}
	cout << "\n---------------------------------------------" << endl;

	ListNode* node = middleNode(n1);
	cout << node->val << endl;




}
