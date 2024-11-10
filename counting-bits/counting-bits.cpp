#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numOfOnes(int n)
    {
        int counter = 0;
        while (n > 0)
        {
            if(n & 1)
                counter++;
            n/=2;
        }
        return counter;
    }

    vector<int> countBits(int n) {
        vector<int> vec;
        for(int i = 0 ; i <= n; i++){
            vec.push_back(numOfOnes(i));
        }
        return vec;
    }
};

int main(void)
{
	vector<int> vec;
	Solution s;
	vec = s.countBits(10);
	
	return 0;
}
