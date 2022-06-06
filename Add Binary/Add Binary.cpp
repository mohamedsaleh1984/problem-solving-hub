 
#include <iostream>
#include <string>
using namespace std;

//https://leetcode.com/problems/add-binary/submissions/
class Solution {
public:
    string addBinary(string a, string b) {
        //Padding Zeros
        if (a.size() > b.size())
        {
            int diff = a.size() - b.size();
            while (diff--)
                b.insert(0, "0");
        }
        else if (b.size() > a.size()) {
            int diff = b.size() - a.size();
            while (diff--)
                a.insert(0, "0");
        }

        string result = "";
        char carry = '0';
        //Calc and Push from front...
        for (int i = a.size() - 1; i >= 0; i--) {
            char tmpA = a[i];
            char tmpB = b[i];

            if (tmpA == tmpB && tmpA == '1')
            {
                if (carry == '0') {
                    result.insert(0, "0");
                    carry = '1';
                }
                else {
                    result.insert(0, "1");
                    carry = '1';
                }

            }
            else if (tmpA == tmpB && tmpA == '0')
            {
                if (carry == '1') {
                    result.insert(0, "1");
                    carry = '0';
                }
                else {
                    result.insert(0, "0");
                }
            }
            else if (tmpA != tmpB)
            {
                if (carry == '1') {
                    result.insert(0, "0");
                    carry = '1';
                }
                else
                {
                    result.insert(0, "1");
                    carry = '0';
                }
            }
        }
        if (carry == '1')
            result.insert(0, "1");
        return result;
    }
};
int main()
{
    string a = "1010";
    string b = "1011";
    Solution s;
    cout << s.addBinary(a, b);
    return 0;
}