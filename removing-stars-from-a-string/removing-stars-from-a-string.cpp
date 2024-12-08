
// https://leetcode.com/problems/removing-stars-from-a-string/submissions/1473359166/?envType=study-plan-v2&envId=leetcode-75
// 23ms Beats 46.41%
// 12/08/2024


class Solution {
public:
    string removeStars(string s) {
        int ptr = 0;
        string str;
        while(ptr < s.length()){
            if(s[ptr] == '*' && str.length() > 0){
                str.pop_back();
            }else{
                str.push_back(s[ptr]);
            }
            ptr++;
        }
        return str;

    }
};
