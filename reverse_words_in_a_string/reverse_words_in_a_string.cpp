// Reverse Words in a String.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

string reverseWords(string s) {
    if (s.length() == 1)
        return s;

    int leftPtr = 0;
    int rightPtr = 0;
    int size = s.length();

    while (rightPtr < size) {

        char rightChar = s[rightPtr];
        //find next space
        while (rightChar != ' ' && rightPtr < size) {
            rightPtr++;
            rightChar = s[rightPtr];
        }
        //
        rightPtr--;
        int tempLeft = leftPtr;
        int tempRight = rightPtr;
        //Swapping 
        while (tempLeft < tempRight) {
            char tempChar = s[tempLeft];
            s[tempLeft] = s[tempRight];
            s[tempRight] = tempChar;
            tempLeft++;
            tempRight--;
        }
        rightPtr += 2;
        leftPtr = rightPtr;
    }
    return s;
}
int main()
{
 
    cout << reverseWords("Let's take LeetCode contest") << endl;
    cout << reverseWords("God Ding") << endl;
    return 0;
}

 