#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/can-place-flowers/
// FIX_IT
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        for (size_t i = 1; i < flowerbed.size() - 1; i++)
        {
            size_t pre = i - 1;
            size_t pos = i + 1;

            if (flowerbed[i] == 0 && flowerbed[pre] == 0 && flowerbed[pos] == 0)
            {
                flowerbed[i] = 1;
                n--;
            }
        }
        return n == 0 ? true : false;
    }
};

int main()
{
    vector<int> vec = {1, 0, 0, 0, 1};
    vector<int> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0};
    int n = 1;
    Solution s;
    cout << (s.canPlaceFlowers(vec, n) ? "Yes" : "No") << endl;

    return 0;
}