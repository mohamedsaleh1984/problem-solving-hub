#include <iostream>
#include <vector>
using namespace std;
//https://leetcode.com/problems/pascals-triangle-ii/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;

        return result;
    }
};
int main()
{
    vector<int> result;
    Solution s = Solution();
    result = s.getRow(10);
    for (auto elem : result)
        cout << elem << " ";

    return 0;
}