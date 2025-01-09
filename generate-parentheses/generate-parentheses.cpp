#include "../common.h"

// https://leetcode.com/problems/generate-parentheses/submissions/1473678107/
// 2ms Beats 82.77%
// 12/08/2024
// the idea is as long as the opening practice are less than N 
// and the closing brackets are less than opening continue.
// once we reach to the valid length Add and backtrack

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur;

        generateParenthesisHelper(res,cur,0,0,n);
        return res;
    }
    void generateParenthesisHelper(vector<string>& vec, string curr, int open, int close,int n)
    {
        if(curr.length() == n*2){
            vec.push_back(curr);
            return;
        }
        if(open < n){
            string newCurr = curr;
            newCurr+="(";
            generateParenthesisHelper(vec,newCurr,open+1,close,n);
        }
        if(close < open)
        {
            string newCurr = curr;   
            newCurr+=")";
            generateParenthesisHelper(vec,newCurr,open,close+1,n);
        }
            
    }
};




int main(int argc,char** argv){
  Solution s;
  vector<string> s = s.generateParenthesis(2);
  for(auto x: s)
    cout << x << endl;


  return 0;
}
