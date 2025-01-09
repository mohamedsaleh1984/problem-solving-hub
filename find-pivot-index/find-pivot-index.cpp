#include "../common.h"

// https://leetcode.com/problems/find-pivot-index/submissions/1473787720/?envType=study-plan-v2&envId=leetcode-75
//0 msBeats 100.00%
// Date: 12/08/2024
/*
    The idea is creating a prefix sum array and
    use it to query the sums on left and right
    have to add 0 at the begining in case we query the first element in the array
 */

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;

        vector<int> prefix(nums.size()+1);
        // construct prefix sum
        for(int i = 0, j =1; i < nums.size() ; i++, j++){
            prefix[j] =  nums[i]+prefix[j-1];
        }

        int lastSum = prefix[prefix.size()-1];

        for(int i = 0; i < nums.size() ; i++){   
            int prefixIndex = i+1;
    
            int left = prefix[prefixIndex] ;
            int right = lastSum - prefix[i];
            
            if(left == right){
                return i;
            }
        }
        return -1;
    }
};


int main(int argc, char** argv){


}
