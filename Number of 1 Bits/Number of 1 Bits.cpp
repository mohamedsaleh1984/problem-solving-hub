#include <iostream>
#include <bitset>
using namespace std;
 //https://leetcode.com/problems/number-of-1-bits/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        std::bitset<32> myset(n);
        int counter = 0;
        for (int i = 0; i < 32; i++)
            counter += myset[i] == 1;
        return counter;
    }
};

int main()
{
    Solution s = Solution();
    cout << s.hammingWeight(5) << endl;


    return 0;
}
