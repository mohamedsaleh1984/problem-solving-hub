#include <iostream>
#include <vector>
using namespace std;
//https://leetcode.com/problems/pascals-triangle/
//TODO:Write it
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;


        return result;
    }
};

int main()
{
    vector<vector<int>> result;
    Solution sol = Solution();
    result = sol.generate(10);
    for (auto vec : result)
    {
        for (auto elem : vec)
            cout << elem << " ";
        cout << endl;
    }

    return 0;
}