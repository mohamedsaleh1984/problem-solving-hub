// DetectCycleLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

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

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

bool has_cycle(SinglyLinkedListNode* head) {

    if (head == nullptr)
        return false;

    SinglyLinkedListNode* slow = head;
    SinglyLinkedListNode* fast = head->next;

    while (slow != nullptr && fast->next != nullptr) {
         if (slow == fast)
            return true;

        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

SinglyLinkedListNode* getNode(SinglyLinkedListNode* head, int nodeVal) {
    SinglyLinkedListNode* root = head;
    while (root != nullptr) {
        if (root->data == nodeVal) {
            return root;
        }
        root = root->next;
    }
    return nullptr;
}

 void makeCycle(SinglyLinkedListNode* head, int to,int from) {
    SinglyLinkedListNode* root = head;
    SinglyLinkedListNode* target = getNode(head,to);


    while (root != nullptr) {
        if (root->data == to) {
            target = root;
        }

        if (root->data == from) {
            root->next = target;
            break;
        }

        root = root->next;
    }
}

int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();
    llist->insert_node(3);
    llist->insert_node(6);
    llist->insert_node(9);
    llist->insert_node(4);
    llist->insert_node(90);
    llist->insert_node(40);

    SinglyLinkedListNode* root = llist->head;
    /*while (root != nullptr) {
        cout << root->data << endl;
        root = root->next;
    }*/

    makeCycle(llist->head, 3, 90);
    root = llist->head;
   /* while (root != nullptr) {
        cout << root->data << endl;
        root = root->next;
    }*/

    ///*while (result != nullptr) {
    //    cout << result->data << endl;
    //    result = result->next;
    //}*/
    std::string res = has_cycle(root) ? "True" : "False";
    cout << res << endl;
    

    return 0;
}
