#include "../common.h"

// https://leetcode.com/problems/the-kth-factor-of-n
// 0ms Beats 100.00%


class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> fac;
        int counter = 0;
        for(int i = 1 ;  i<= n ; i++){
            if(n%i == 0){
                fac.push_back(i);
                counter++;
                if(counter == k)
                    break;
            }
        }

        if(fac.size() < k)
            return -1;
        return fac[k-1];
    }
};




int main(int argc,char** argv){
    Solution s;
    cout << s.kthFactor(4,4) << endl;
    return 0;
}
