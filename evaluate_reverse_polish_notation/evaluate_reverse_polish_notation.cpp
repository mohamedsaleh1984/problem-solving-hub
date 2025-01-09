#include "../common.h"

/*
https://leetcode.com/problems/evaluate-reverse-polish-notation/
Runtime: 20 ms, faster than 24.82% of C++ online submissions for Evaluate Reverse Polish Notation.
Memory Usage: 12 MB, less than 21.76% of C++ online submissions for Evaluate Reverse Polish Notation.
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stck;
        int firstOperand = 0, secondOperand = 0;

        for (int i = 0; i < tokens.size(); i++)
        {
            string val = tokens[i];

            if (isOperator(tokens[i]))
            {
                secondOperand = stck.top();
                stck.pop();
                int result = 0;
                if (!stck.empty()) {
                    firstOperand = stck.top();
                    stck.pop();
                }

                if (tokens[i][0] == '+') {
                    result = firstOperand + secondOperand;
                }
                else if (tokens[i][0] == '-') {
                    result = firstOperand - secondOperand;
                }
                else if (tokens[i][0] == '*') {
                    result = firstOperand * secondOperand;
                }
                else if (tokens[i][0] == '/') {
                    result = firstOperand / secondOperand;
                }
                stck.push(result);
                firstOperand = 0;
                secondOperand = 0;
            }
            else
            {
                stck.push(stoi(tokens[i]));
            }
        }
        
        return stck.top();
    }

    bool isOperator(string input) {
        if (input.length() ==1 && (input[0] == '+' || input[0] == '-' || input[0] == '*' || input[0] == '/'))
            return true;
        return false;
    }
};

int main()
{
    vector<string> str { "2", "1","+","3","*" };
    vector<string> str2{ "4","13","5","/","+" };
    vector<string> str3{ "10","6","9","3","+","-11","*","/","*","17","+","5","+" };

    Solution s;
    cout << s.evalRPN(str) << endl;
    cout << s.evalRPN(str2) << endl;
    cout << s.evalRPN(str3) << endl;
 
    return 0;
}
