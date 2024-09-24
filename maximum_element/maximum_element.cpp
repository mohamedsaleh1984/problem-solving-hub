// Maximum Element.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;


class MaxStack {
public:
    int pop() {
        int elem = S.top();
        S.pop();
        return elem;
    }

    void push(int elem) {
        if (S.empty())
            S.push(elem);
        else
        {
            int top = S.top();
            if (elem < top) {
                stack<int> s2;
                while (elem < S.top()) {
                    int c = S.top();
                    S.pop();
                    s2.push(c);
                }
                S.push(elem);

                while (!s2.empty())
                {
                    int c = s2.top();
                    s2.pop();
                    S.push(c);
                }
            }
            else
            {
                S.push(elem);
            }
        }

    }

    int top() {
        return S.top();
    }

private:
    stack<int> S;
};

vector<int> getMax(vector<string> operations) {
    vector<int> vec;
    MaxStack* cls = new MaxStack();
   
    for (int i = 0; i < operations.size(); ++i) {

        char op = operations[i][0];
        if (op == '1') {
            cout << operations[i] << endl;

            string val = operations[i].substr(2, operations[i].length() - 1);
            int elem = atoi(val.c_str());

            cls->push(elem);
        }
        else if (op == '2') {
            cls->pop();
        }
        else if (op == '3') {
            cout << cls->top() << endl;
            vec.push_back((cls->top()));
        }

    }


    return vec;

}


int main()
{
    //MaxStack* cls = new MaxStack();
    //int input = -1;
    //for (int i = 0; i < 10; i++) {
    //    cin >> input;

    //    if (input == 0)
    //    {
    //        int n = 0;
    //            cin >> n;
    //        cls->push(n);
    //    }
    //    else if (input == 1)
    //    {
    //        cout << cls->top();
    //    }
    //    else if (input == 2) {
    //        cout << cls->pop();
    //    }
    //}


    vector<string> ops(10);
    ops[0] = "1 97";
    ops[1] = "2";
    ops[2] = "1 20";
    ops[3] = "2";
    ops[4] = "1 26";
    ops[5] = "1 20";
    ops[6] = "2";
    ops[7] = "3";
    ops[8] = "1 91";
    ops[9] = "3";
        
    vector<int> res = getMax(ops);
    for (size_t i = 0; i < res.size(); i++) {
        cout << res[i];

        if (i != res.size() - 1) {
            cout << "\n";
        }
    }
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
