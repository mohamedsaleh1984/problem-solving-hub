#include "../common.h"

// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
// 2ms Beats 13.01%
class Solution {
public:
    bool isMatching(string s, string e, int start){
        for(int i = 0, j = start ; i < e.length() ; i++,j++){
            if(s[j] != e[i])
                return false;
        }
        return true;
    }

    int strStr(string haystack, string needle) {
        int index = -1;
        int lenOfNeedle = needle.size();
        int lenOfHay = haystack.size();

        for(int i = 0 ; i < lenOfHay ; i++){
            int rem = lenOfHay - i;
            if(haystack[i] == needle[0] && rem>=lenOfNeedle && isMatching(haystack,needle,i)){
                return i;
            }
        }
        return index;    
    
    }
};


int main(void){ 
    //haystack = "sadbutsad", needle = "sad";
    string haystack = "leetcode", needle = "leeto";
    Solution s;
    cout << s.strStr(haystack,needle) << endl;

    return 0;   
}
