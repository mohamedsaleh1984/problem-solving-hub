#include "../common.h"

//https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/559/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits[digits.size() - 1] < 9) {
            digits[digits.size() - 1]++;
            return digits;
        }

        vector<int> vec;
        int carry = 0;
        int rightMost = digits.size() - 1;

        for (int i = rightMost; i >= 0 ; i--) 
        {    
            if (1 + digits[i] >= 10 && i == rightMost) {
                if (1 + digits[i] == 10) {
                    vec.push_back(0); 
                }
                else {
                    vec.push_back((1 + digits[i]) - 10);
                }
                carry = 1;
            }
            else 
            {
                if (digits[i] + carry >= 10) {
                    if (carry + digits[i] == 10) {
                        vec.push_back(0);
                    }
                    else {
                        vec.push_back((carry + digits[i]) - 10);
                    }
                    carry = 1;
                }
                else {
                    
                    vec.push_back(digits[i] + carry);
                    carry = 0;
                }       
            }
        }

        if (carry > 0) {
            vec.push_back(carry);
        }

        reverse(vec.begin(), vec.end());
        return vec;
    }


};

void printOut(vector<int> vec) {
    for (auto x : vec)
        cout << x << " ";
    cout << endl;
}

int main()
{
    vector<int> result = {};
	vector<int> digits = {9 };
    Solution  s;
    result = s.plusOne(digits);
    printOut(result);
	vector<int> digits2 = { 9,9 };
    result = s.plusOne(digits2);
    printOut(result);
	return 0;
}