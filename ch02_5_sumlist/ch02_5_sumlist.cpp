#include "../common.h"

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

SinglyLinkedListNode* ReverseLL(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* prev = nullptr;

    while (head != nullptr) {
        SinglyLinkedListNode* next = head->next;
        head->next = prev;
        prev = head;
        if (next == nullptr) {
            break;
        }
        head = next;
    }
    return head;
}

SinglyLinkedList* GetSumListsMethod1(SinglyLinkedListNode* l1, SinglyLinkedListNode* l2) {
    SinglyLinkedList* lis = new SinglyLinkedList();
    int carry = 0;

    while (l1 != nullptr && l2 != nullptr) {
        int val = l1->data + l2->data + carry;
        if (val > 10) {
            lis->insert_node(val % 10);
            carry = val / 10;
        }
        else
        {
            lis->insert_node(val);
        }
        l1 = l1->next;
        l2 = l2->next;
    }

    if (l1 != nullptr) {
        while (l1 != nullptr) {
            lis->insert_node(l1->data);
            l1 = l1->next;
        }
    }

    if (l2 != nullptr) {
        while (l2 != nullptr) {
            lis->insert_node(l2->data);
            l2 = l2->next;
        }
    }

    return lis;
}

SinglyLinkedList* GetSumListsMethod2(SinglyLinkedListNode* l1, SinglyLinkedListNode* l2) {
    l1 = ReverseLL(l1);
    l2 = ReverseLL(l2);
    return GetSumListsMethod1(l1, l2);
}

int GetListValue(SinglyLinkedListNode* ls)
{
    stack<int> S;
    while (ls != nullptr) {
        S.push(ls->data);
        ls = ls->next;
    }
    int val = 0;
    int iCounter = 0;
    while (!S.empty()) {
        int digit = S.top() * pow(10, iCounter);
        S.pop();
        val += digit;
        iCounter++;
    }
    return val;
}

 

int main()
{
    /*SinglyLinkedList* l1 = new SinglyLinkedList();
    l1->insert_node(7);
    l1->insert_node(1);
    l1->insert_node(6);
    SinglyLinkedList* l2 = new SinglyLinkedList();
    l2->insert_node(5);
    l2->insert_node(9);
    l2->insert_node(2);


    SinglyLinkedList* sm= GetSumListsMethod1(l1->head, l2->head);
    SinglyLinkedListNode* root = sm->head;
    while (root != nullptr) {
        cout << root->data << endl;
        root = root->next;
    }*/
    SinglyLinkedList* l1 = new SinglyLinkedList();
    l1->insert_node(6);
    l1->insert_node(1);
    l1->insert_node(7);

    l1->head = ReverseLL(l1->head);
    while (l1->head != nullptr) {
       cout << l1->head->data << endl;
       l1->head = l1->head->next;
   }
    //SinglyLinkedList* l2 = new SinglyLinkedList();
    //l2->insert_node(2);
    //l2->insert_node(9);
    //l2->insert_node(5);


    //SinglyLinkedList* sm = GetSumListsMethod2(l1->head, l2->head);
    //SinglyLinkedListNode* root = sm->head; 
}
 
