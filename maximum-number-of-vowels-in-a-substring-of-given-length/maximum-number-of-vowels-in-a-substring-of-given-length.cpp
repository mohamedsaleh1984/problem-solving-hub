#include "../common.h"

// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length
// 4ms Beats79.57%
// 12/24/2024

class Solution {
public:
    bool isVolwels(char x) {
        return (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u');
    }

    int maxVowels(string s, int k) {
        std::deque<int> mydeque;
        int globalMax = INT_MIN;
        int window = 0;

        for (int i = 0; i < k; i++) {
            if(isVolwels(s[i])){
                window++;
            }
            mydeque.push_back(s[i]);
        }
        
        globalMax = max(globalMax,window);

        int index = k;
        while(index< s.size() ){

            char f =  mydeque.front();
            
            mydeque.pop_front();
            if(isVolwels(f)){
                window--;
            }

            char c  = s[index];
             if(isVolwels(c)){
                window++;
            }
            
            mydeque.push_back(c);
            
            globalMax = max(globalMax,window);

            index++;
        }
        return globalMax;

    }
};

int main()
{
    vector<string> vec = {"abciiidef", "aeiou", "leetcode","tryhard"};
    vector<int> vecK = {3, 2, 3,4};
    Solution s;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << s.maxVowels(vec[i],vecK[i]) << endl; 
    }
    return 0;
}
