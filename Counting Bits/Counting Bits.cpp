#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
//https://leetcode.com/problems/counting-bits/
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> vec(n + 1);
        for (int i = 0; i <= n; i++) {
            vec[i] = numberOfOnces(i);
        }
        return vec;
    }

    int numberOfOnces(uint32_t n) {
        std::bitset<32> myset(n);
        int counter = 0;
        for (int i = 0; i < 32; i++)
            counter += myset[i] == 1;
        return counter;
    }
};

void printOut(vector<int> v) {
    for (auto elm : v)
        cout << elm;
}
int main()
{
    Solution s = Solution();
    int n = 2;
    vector<int> bits = s.countBits(n);
    printOut(bits);
    
    return 0;
}
