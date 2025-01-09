#include "../common.h"

// https://leetcode.com/problems/reverse-vowels-of-a-string/submissions/1467727825/?envType=study-plan-v2&envId=leetcode-75
// 8msBeats 9.63%
// 12/01/2024

class Solution
{
public:
    bool isVowel(char c)
    {
        if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' ||
            c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U')
            return true;
        return false;
    }
    string reverseVowels(string s)
    {
        string strOut;
        unordered_map<int, char> postions;
        int pos = 0;
        int len = s.length();

        // first pass to get all vowels
        for (int i = 0; i < len; i++)
        {
            if (isVowel(s[i]))
            {
                postions.insert({pos, s[i]});
                pos++;
            }
        }

        pos--;

        for (int i = 0; i < len; i++)
        {
            if (isVowel(s[i]))
            {
                strOut += postions[pos];
                pos--;
            }
            else
            {
                strOut += s[i];
            }
        }

        return strOut;
    }
};
