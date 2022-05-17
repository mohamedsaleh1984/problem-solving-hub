// QueueWith2Stacks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
using namespace std;

class MQueue {
public:
    MQueue() {

    }
    int dequeue() {

        if (!s1.empty() && s2.empty()) {
            while (!s1.empty()) {
                int elem = s1.top();
                s1.pop();
                s2.push(elem);
            }
            int top = s2.top();
            s2.pop();
            return top;
        }

        if (!s2.empty())
        {
            int top = s2.top();
            s2.pop();
            return top;
        }
        if (s2.empty())
            return -1;
    }

    void enqueu(int elem) {
        s1.push(elem);
    }
private:
    stack<int> s1; // enqueu
    stack<int> s2;
};


int main()
{
    MQueue q;
    q.enqueu(10);
    q.enqueu(20);
    q.enqueu(30);

    cout << q.dequeue() << endl;
    q.enqueu(40);
    cout << q.dequeue() << endl;
    q.enqueu(50);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    return 0;
}
