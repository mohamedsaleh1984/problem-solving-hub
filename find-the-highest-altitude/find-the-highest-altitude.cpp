#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int imax = 0;
        
        vector<int> prefix(gain.size());
        prefix[0] = gain[0];

        imax = max(imax,prefix[0]);
        
        for(int i = 1; i < gain.size() ; i++){
            prefix[i] =  gain[i]+prefix[i-1];
            imax = max(imax,prefix[i]);
        }

        return imax;
    }
};

int main(int argc,char** agrv){
    Solution s;
    vector<int> gain={-5,1,5,0,-7};
    cout << s.largestAltitude(gain);
    return 0;
}