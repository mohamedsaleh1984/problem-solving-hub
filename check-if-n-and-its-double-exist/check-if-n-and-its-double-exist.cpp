#include "../common.h"

//https://leetcode.com/problems/check-if-n-and-its-double-exist/?envType=daily-question&envId=2024-12-01
//

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int> xmap;
        //6 2 14 22
        for(int i = 0 ; i < arr.size() ; i++){
            xmap.insert({arr[i],i});
        }

        for(int i = 0 ;  i < arr.size() ; i++){
            int d = arr[i] * 2;
            if(xmap.count(d) > 0 && xmap[d] != i){
                return true;
            }
        }

        return false;
    }
    
    bool checkIfExist(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr.size(); j++) {
                if (i != j && arr[i] == arr[j] * 2) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main(int argc, char** argv)
{
  Solution s;
  vector<int> vec={10,2,5,3};
  cout << s.checkIfExist(vec) << endl;
  return 0;
}
