// Longest Substring without Repeating Characters.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
#include <string>
using namespace std;


void viewSet(set<char> bb) {
    std::set<char>::iterator setIter;
    setIter = bb.begin();
    cout << "{ ";
    while (setIter != bb.end()) {
        cout << *setIter << " ";
        setIter++;
    }
    cout << " }";
}


int longest_substring_without_repeating_characters(std::string s) {
    if (s.length() == 1)
        return 1;

    int start = 0, end = 0, maxLength = 0, windlen = 0;
    set<char> window;
    std::set<char>::iterator it;
    while (end < s.length())
    {
        it = window.find(s[end]);
        if (it == window.end())
        {
            window.insert(s[end]);
            end++;
        }
        else
        {
            window.erase(s[start]);
            start++;
        }
        maxLength = max(maxLength, end-start);
    }
    
    
    return maxLength;
}

int main() { 
    string s = "abccabcabcc";
    int res = longest_substring_without_repeating_characters(s);
    std::cout << res << '\n';
}