#include "../common.h"

// https://leetcode.com/problems/reverse-vowels-of-a-string/

class Solution
{
public:
    void swap(string &s, int left, int right)
    {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
    }

    bool IsVowels(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }

    string reverseVowels(string s)
    {
        if (s.length() == 1)
            return s;

        int leftVowelsPtr = 0;
        int rightVowelsPtr = s.length() - 1;
        int size = s.length();

        while (leftVowelsPtr < rightVowelsPtr)
        {
            while (!IsVowels(s[leftVowelsPtr]) && leftVowelsPtr < rightVowelsPtr)
                leftVowelsPtr++;
            while (!IsVowels(s[rightVowelsPtr]) && rightVowelsPtr > leftVowelsPtr)
                rightVowelsPtr--;

            if (IsVowels(s[leftVowelsPtr]) && IsVowels(s[rightVowelsPtr]))
            {
                if (s[leftVowelsPtr] != s[rightVowelsPtr])
                {
                    swap(s, leftVowelsPtr, rightVowelsPtr);
                }
                leftVowelsPtr++;
                rightVowelsPtr--;
            }
        }
        return s;
    }
};

int main()
{
    string s = ".,";
    Solution S;
    cout << S.reverseVowels(s) << endl;
    return 0;
}