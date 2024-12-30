#include "../common.h"

void substrings(string str)
{
    // O(n^3)
    for(int start=0 ; start < (int)str.size() ; ++start){
        for(int end = start ; end < (int)str.size(); ++end){
            cout << str.substr(start,end-start+1) << "\n";
        }
    }
    cout << endl;
}

void substrings2(string str)
{
    // try all size
    for(int sz=1 ; sz <= (int) str.size() ; ++sz){
        for(int start = 0 ; start+sz <= (int) str.size() ; ++start){
            cout << str.substr(start,sz) << "\n";
        }
    }
    cout << endl;
}


int main()
{
    substrings("abc");
    substrings2("abc");
}