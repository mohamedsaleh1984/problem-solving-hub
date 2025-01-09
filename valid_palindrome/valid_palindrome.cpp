#include "../common.h"
// https://leetcode.com/problems/valid-palindrome/
/*
Runtime: 8 ms, faster than 55.37% of C++ online submissions for Valid Palindrome.
Memory Usage: 7.9 MB, less than 16.98% of C++ online submissions for Valid Palindrome.
Next challenges:
*/
class Solution
{
public:
    bool isPalindrome(string s)
    {
        string s2 = normalize(s);
        return checkIsPal(s2);
    }
    bool checkIsPal(string s)
    {
        if (s.length() == 0 || s.length() == 1)
            return true;

        int iLeft = 0;
        int iRight = s.length() - 1;

        while (iLeft < iRight)
        {
            if (s[iLeft] != s[iRight])
                return false;
            iLeft = iLeft + 1;
            iRight--;
        }
        return true;
    }

    string normalize(string s)
    {
        string s2 = "";
        for (int i = 0; i < s.length(); i++)
        {
            // Capital
            if (s[i] >= 65 && s[i] <= 90)
                s2 += s[i] + 32;
            // Lower case
            if (s[i] >= 97 && s[i] <= 122)
                s2 += s[i];
            // numbers
            if (s[i] >= 48 && s[i] <= 57)
                s2 += s[i];
        }
        return s2;
    }
};
int main()
{
    Solution s;
    string s2 = "A man, a plan, a canal: Panama";
    cout << s.isPalindrome(s2);

    return 0;
}
