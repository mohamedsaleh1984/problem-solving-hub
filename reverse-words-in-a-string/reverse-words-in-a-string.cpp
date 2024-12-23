

#include "../common.h"
//https://leetcode.com/problems/reverse-words-in-a-string/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    void trim(string& s){
          s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
         s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
    }

    string reverseWords(string s) {
        vector <string> tokens;
        stringstream check1(s);
        string inter;
        while(getline(check1,inter,' '))
        {
            trim(inter);
            if(inter.size()>0){
                tokens.push_back(inter);
            }    
        }

        string strRes;
        for(int i = tokens.size()-1 ; i >=0  ; i--){
            strRes+=tokens[i];
            if(i>=0)
                strRes+=' ';
        }
        strRes = strRes.substr(0,strRes.size()-1);
        return strRes;
        
    }
};

