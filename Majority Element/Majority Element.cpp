#include <iostream>
#include <vector>
#include <map>
using namespace std;
//https://leetcode.com/problems/majority-element/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> data;
        for (auto item : nums) {
            data[item]++;
        }

        int range = (nums.size() / 2) + 1;
        map<int, int>::iterator it = data.begin();
        int numToReturn = 0;
        while (it != data.end())
        {
            if (it->second >= range) {
                numToReturn = it->first;
            }
            it++;
        }

        return numToReturn;
    }
};
int main()
{
     
}
 