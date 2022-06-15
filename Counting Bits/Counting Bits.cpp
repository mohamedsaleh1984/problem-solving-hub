#include <iostream>
#include <vector>
using namespace std;
//https://leetcode.com/problems/counting-bits/
//TODO:Write it
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n+1);
        bits[0] = 0;
        bits[1] = 1;
        int carry = 0;
        for (int i = 2; i <= bits.size(); i++) {
            int previousNum = bits[i - 1];
            
            


        }

        return bits;
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
