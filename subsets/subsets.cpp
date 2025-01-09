#include "../common.h"

//TODO: Correct it
void perm(vector<int>& perm, vector<int>& selected, vector<int>& list) {

    if (perm.size() == list.size())
    {
        
    }

}
int main()
{
	vector<int> nums = { 1 };
    vector<vector<int>> output = {};
    output.push_back({});

    for (int num : nums) {
        vector<vector<int>>  newSubsets = {};
        for (vector<int> curr : output) {
            newSubsets.push_back({curr});
        }
        for (vector<int>  curr : newSubsets) {
            output.push_back(curr);
        }
    }

    for (auto set : output) {
        for (auto elem : set) {
            cout << elem << " ";
        }
        cout << "\n";
    }

}
