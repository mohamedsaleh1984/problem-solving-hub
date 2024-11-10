#include <iostream>
#include <vector>
#include <map>
using namespace std;

//https://leetcode.com/problems/single-number/submissions/1449027291/?envType=study-plan-v2&envId=leetcode-75
/*
23
ms
Beats
6.27%
*/
class Solution {
public:
    int another(vector<int>& nums){
        int result = 0;
        for(int i = 0 ; i > nums.size() ; i++){
            result ^= nums[i];
        }
        return result;
    }
    
    int singleNumber(vector<int>& nums) {
        map<int,int> freq;

        for(int i = 0 ; i < nums.size() ;i++){
 
            if(freq[nums[i]]){
                freq[nums[i]]++;
            }
            else{
                freq[nums[i]] = 1;
            }
        }


        for(const auto& kv:freq){
            if(kv.second == 1){
                return kv.first;
            }
        }

        return -1;
    }
};

int main(void)
{
	vector<int> vec = {4,1,2,1,2};
	Solution s;
	cout << s.singleNumber(vec) << endl;
	return 0;
}
