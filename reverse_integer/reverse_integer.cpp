// Reverse Integer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
using namespace std;

int reverse(int x) {
    int digit;
    int revered = 0;
    bool neg = x < 0 ? true : false;
    stack<int> space;

    if (x <= INT_MIN || x >= INT_MAX)
        return 0;

    if (neg) {
        x = x * -1;
    }

    while (x > 0) {
        digit = x % 10;
        space.push(digit);
        x = x / 10;
    }
    int index = 0;
    while (!space.empty())
    {
        digit = space.top();
        space.pop();
        long long int temp = revered + digit * pow(10, index);
        if (temp > INT_MAX || temp < INT_MIN) {
            return 0;
        }
        revered += digit * pow(10, index);
        index++;
    }
    return neg ? revered * -1 : revered;
}

int main()
{
    //cout << reverse(123) << endl;
    //cout << reverse(-123) << endl;
    //cout << reverse(120) << endl;
    cout << reverse(1534236469) << endl;
    cout << reverse(-2147483641) << endl;
}
