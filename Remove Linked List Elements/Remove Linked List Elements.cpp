#include <iostream>


//https://leetcode.com/problems/remove-linked-list-elements/
class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
    }

    void insert(int node_data) {
        ListNode* node = new ListNode(node_data);

        if (!this->head) {
            this->head = node;
        }
        else {
            this->tail->next = node;
        }

        this->tail = node;
    }
};
int main()
{
    ListNode* list1 = new ListNode(6);
    list1->insert(5);
    list1->insert(4);
    list1->insert(3);
    list1->insert(6);
    list1->insert(2);
    list1->insert(1);
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
