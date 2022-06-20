#include <iostream>
#include <string>
using namespace std;
//https://leetcode.com/problems/implement-strstr/
class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if (needle.size() > haystack.size())
            return -1;
        if (needle.size() == haystack.size()) {
            for (int i = 0; i < needle.size(); i++)
            {
                if (needle[i] != needle[i])
                    return -1;

            }
            return 0;
        }

        int iIndex = -1;
        int iComp = 0;

        for (int i = 0; i < haystack.size(); i++) {

            if (haystack[i] == needle[0]) {
                if (i + needle.size() > haystack.size()) {
                    return iIndex;
                }
                else
                {
                    int j = i;
                    iComp = 0;
                    iIndex = i;
                    while (true) {
                        if (haystack[j] == needle[iComp])
                        {
                            j++;
                            iComp++;
                        }
                        else
                        {
                            if (iComp == needle.size()) {
                                break;
                            }
                            
                            iIndex = -1;
                            break;
                        }
                    }

                    if (iIndex != -1)
                        break;
                }
            }
        }
        return iIndex;
    }
};

int main()
{
    string haystack = "abc", needle = "c";
    Solution s = Solution();
    cout << s.strStr(haystack, needle) << endl;

    return 0;
}