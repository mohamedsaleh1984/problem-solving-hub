#include <iostream>
#include <vector>
#include <bitset>
#include <climits>
#include <cstdint>
using namespace std;

// https://leetcode.com/problems/counting-bits/
// 3ms Beats 24.68%
// 12/02/2024

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> vec(n + 1);
        for (int i = 0; i <= n; i++)
        {
            vec[i] = numberOfOncesBitSet(i);
        }
        return vec;
    }

    int numberOfOncesBitSet(uint32_t n)
    {
        std::bitset<32> myset(n);
        int counter = 0;
        for (int i = 0; i < 32; i++)
            counter += myset[i] == 1;
        return counter;
    }
    int numOfOnesDivision(int n)
    {
        int counter = 0;
        while (n > 0)
        {
            if (n & 1)
                counter++;
            n /= 2;
        }
        return counter;
    }
};

void printOut(vector<int> v)
{
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
