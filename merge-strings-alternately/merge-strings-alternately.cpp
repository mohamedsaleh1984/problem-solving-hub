#include <iostream>
#include <vector>
using namespace std;

// 12/01/2024
// https://leetcode.com/problems/merge-strings-alternately
// 3ms Beats 44.38%

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l = min(word1.length(), word2.length());
        int i = 0;
        string sout;

        while(i<l){
            sout+=word1.at(i);
            sout+=word2.at(i);
            i++;
        }

        if(word1.length() != l){
            sout+= word1.substr(l,word1.length());
        }

        if(word2.length() != l){
            sout+= word2.substr(l,word2.length());
        }
        

        return sout;
    }
};
int main()
{

    return 0;
}
