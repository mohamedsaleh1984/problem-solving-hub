#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
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
