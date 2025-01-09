#include "../common.h"

class SinglyLinkedList {

private:
    int counter = 0;
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
        counter++;
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

    int count() {
        return counter;
    }

    int findMiddleElement() {
        SinglyLinkedListNode* copyHead = head;
        SinglyLinkedListNode* nextNextHead = head;
        if (copyHead->next == nullptr)
            return copyHead->data;


        if (nextNextHead->next == nullptr|| nextNextHead->next->next == nullptr)
        {
            cout << "At least 3 items in the list required to perform." << endl;
            return -1;
        }
        else {
            nextNextHead = head->next->next;
        }

        while (nextNextHead->next != nullptr) {
            copyHead = copyHead->next;
            nextNextHead = nextNextHead->next;
        }

        return copyHead->data;
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

    cout << l1->findMiddleElement() << endl;
}
