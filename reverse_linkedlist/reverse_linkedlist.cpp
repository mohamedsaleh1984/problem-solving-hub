#include "../common.h"

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

    void print() {
        SinglyLinkedListNode* headCopy = head;
        while (headCopy != NULL) {
            cout << headCopy->data;
            if (headCopy->next != NULL)
                cout << "-> ";
            headCopy = headCopy->next;
        }
    }

    void reverse() {
      
        SinglyLinkedListNode* prev = nullptr;

        while (head != nullptr)
        {
            SinglyLinkedListNode* next = head->next;
            head->next = prev;
            prev = head;
            if (next == nullptr)break;
            head = next;
        }
         
    }
};

int main()
{
    SinglyLinkedList* l1 = new SinglyLinkedList();
    l1->insert_node(6);
    l1->insert_node(1);
    l1->insert_node(7);
    l1->insert_node(10);
    l1->insert_node(20);
    l1->insert_node(78);
    l1->print();
    l1->reverse();
    cout << endl;
    l1->print();

    return 0;
}
