#include <iostream>
#include <vector>
#include <map>
using namespace std;

//https://leetcode.com/problems/letter-combinations-of-a-phone-number/
//0 ms Beats 100.00%
class Solution {
public:

    vector<string> letterCombinations(string digits) {
        vector<string> resultSet;
        if(digits.length()==0)
            return resultSet;

        mapper.insert(pair<char, string>{'2', "abc"});
        mapper.insert(pair<char, string>{'3', "def"});
        mapper.insert(pair<char, string>{'4', "ghi"});
        mapper.insert(pair<char, string>{'5', "jkl"});
        mapper.insert(pair<char, string>{'6', "mno"});
        mapper.insert(pair<char, string>{'7', "pqrs"});
        mapper.insert(pair<char, string>{'8', "tuv"});
        mapper.insert(pair<char, string>{'9', "wxyz"});

        string entry;
        int index = 0;
        Solve(digits,entry,resultSet,index);

        return resultSet;
    }
   
    void Solve(string digits,string& entry, vector<string>& resultSet, int index) {
        if(entry.size() == digits.size()){
            resultSet.push_back(entry);
            return;
        }
 
        string value  = mapper[digits[index]];
        for(int i = 0 ; i < value.length() ; i++){
           string newEntry =  entry;
           newEntry.push_back(value[i]);
           Solve(digits,newEntry,resultSet,index+1);
        }
    }

private:
    map<char, string> mapper;
};

int main()
{
    map<char, string> mapper;
    mapper.insert(pair<char, string>{'2', "abc"});
    mapper.insert(pair<char, string>{'3', "def"});
    mapper.insert(pair<char, string>{'4', "ghi"});
    mapper.insert(pair<char, string>{'5', "jkl"});
    mapper.insert(pair<char, string>{'6', "mno"});
    mapper.insert(pair<char, string>{'7', "pqrs"});
    mapper.insert(pair<char, string>{'8', "tuv"});
    mapper.insert(pair<char, string>{'9', "wxyz"});
    Solution s;

    string digits = "249";
       
    vector<string> vec = s.letterCombinations(digits);
    for (auto a : vec)
        cout << a << " ";

    return 0;
}
 