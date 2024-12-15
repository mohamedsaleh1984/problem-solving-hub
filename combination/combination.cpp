
#include <iostream>
#include <vector>
#include <set>
#include "../common.h"
using namespace std;

// https://leetcode.com/problems/combinations/submissions/1479566243/
// 12/15/2024
// 75 ms Beats 42.38%

class Solution
{
private:
    vector<vector<int>> result;

    void backtrack(int start, int n, int k, vector<int>& path) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }

        for (int i = start; i <= n; ++i) {
            path.push_back(i);
            backtrack(i + 1, n, k, path);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> set={};
        backtrack(1,n,k,set);
        return result;
    }

    vector<vector<int>> combination(vector<int> arr)
    {
        if (arr.size() == 0)
        {
            vector<vector<int>> vec;
            vector<int> emptySet;
            vec.push_back(emptySet);
            return vec;
        }

        // [a,b,c]
        int first = arr[0]; // get first element  => a
        vector<int> rest;   // => [b,c]
        copy(arr.begin() + 1, arr.end(), back_inserter(rest));

        vector<vector<int>> combsWithoutFirst = combination(rest);

        vector<vector<int>> combsWithFirst;

        for (int i = 0; i < combsWithoutFirst.size(); i++)
        {
            vector<int> newCopy;
            copy(combsWithoutFirst[i].begin(), combsWithoutFirst[i].end(), back_inserter(newCopy));
            newCopy.push_back(first);

            combsWithFirst.push_back(newCopy);
        }

        vector<vector<int>> combinedResult;
        copy(combsWithFirst.begin(), combsWithFirst.end(), back_inserter(combinedResult));
        copy(combsWithoutFirst.begin(), combsWithoutFirst.end(), back_inserter(combinedResult));
        
        return combinedResult;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    vector<vector<int>> vec = s.combine(4, 2);
  //  vector<int> vec1 = {1,2,3};

    // vector<vector<int>> result  = s.combination(vec1);
      printvector(vec);
    // cout << endl;

    return 0;
}