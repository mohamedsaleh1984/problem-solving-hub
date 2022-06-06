#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
//https://leetcode.com/problems/longest-common-prefix/
//TODO: solve
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";

        if (strs.size() == 1)
            return strs[0];

      /*  string pref = to_string(strs[0]);

        longestCommonPrefixLookup(strs, 0, pref);*/

        return pref;
    }

    void longestCommonPrefixLookup(vector<string>& strs, int currentIndex, string& pref) {

    }
};

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
