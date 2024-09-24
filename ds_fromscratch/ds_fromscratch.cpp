
#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

void insert(int x) {

    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;


    if (head != NULL) {
        temp->next = head;   
    }
    head = temp;
}

void print(struct Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}


int main()
{
    insert(10); insert(50); insert(13); insert(11);
    print(head);

}
