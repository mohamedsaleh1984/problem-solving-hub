

#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int len = arr.size();
        int ans = 0; 
        for(int i = 1 ; i<= len -2 ; ){
            
            //left side of the mountain.
            if(arr[i]> arr[i-1] && arr[i]> arr[i+1]){
                //find the length
                int j = i;
                int count = 1;
                while(j >0 && arr[j] > arr[j-1]){
                    j--;
                    count++;
                }
                
                while(i < len-1 && arr[i] > arr[i+1])      
                {
                    i++;
                    count++;
                }
                ans = max(ans,count);
            }else{
                i++;
            }
        }
        return ans;
    }
};

int main(void)
{

    vector<int> nums = {2,1,4,7,3,2,5};
    Solution s;
    s.maxProduct(nums);

    return 0;
}