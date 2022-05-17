// Sort ist.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
    }

};
class SinglyLinkedList {
public:
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;

    SinglyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data) {
        SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

        if (!this->head) {
            this->head = node;
        }
        else {
            this->tail->next = node;
        }

        this->tail = node;
    }
};

/*
Given the head of a linked list, return the list after sorting it in ascending order.
*/
SinglyLinkedListNode* sortList(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* headPtr = head;
    SinglyLinkedListNode* headTmp = head;
    bool NoSwaps = false;

    while (headPtr != NULL) {
        SinglyLinkedListNode* mover = headPtr;
        if (headPtr->data > mover->data) {
            int tmp = headPtr->data;
            headPtr->data = mover->data;
            mover->data = tmp;
            mover = mover->next;
        }
        else {
            headPtr = headPtr->next;
        }

    }

    return headTmp;
}
 

int main()
{
    SinglyLinkedList* l1 = new SinglyLinkedList();
    l1->insert_node(3);
    l1->insert_node(1);
    l1->insert_node(2);
    l1->insert_node(4);

    SinglyLinkedListNode* res = sortList(l1->head);
}
