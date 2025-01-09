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
};

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedList* list = new SinglyLinkedList();

    while (true) {
        
         if (head1 == nullptr && head2 != nullptr) {
            while (head2 != nullptr) {
                list->insert_node(head2->data);
                head2 = head2->next;
            }
            break;
        }
        else if (head2 == nullptr && head1 != nullptr) {
            while (head1 != nullptr) {
                list->insert_node(head1->data);
                head1 = head1->next;
            }
            break;
        }
        else if (head2 == nullptr && head1 == nullptr)
        {
            break;
        }
        else if (head1->data == head2->data) {
            list->insert_node(head1->data);
            list->insert_node(head1->data);

            head1 = head1->next;
            head2 = head2->next;
        }
        else if (head1->data > head2->data) {
            list->insert_node(head2->data);
            head2 = head2->next;
        }
        else if (head1->data < head2->data) {
            list->insert_node(head1->data);
            head1 = head1->next;
        }
    }
    return list->head;
}


int main()
{
    SinglyLinkedList* list1 = new SinglyLinkedList();
    list1->insert_node(1);
    list1->insert_node(1);
    list1->insert_node(2);
    list1->insert_node(2);

    SinglyLinkedList* list2 = new SinglyLinkedList();
    list2->insert_node(2);
    list2->insert_node(2);
    list2->insert_node(3);
    list2->insert_node(4);


    SinglyLinkedListNode* result = mergeLists(list1->head, list2->head);
    while (result != nullptr) {
        cout << result->data << endl;
        result = result->next;
    }


}
