#include <iostream>
#include <vector>
#include <map>
using namespace std;
//https://leetcode.com/problems/letter-combinations-of-a-phone-number/
//TODO: Fix it
class Solution {
public:

    Solution() {
        mapper.insert(pair<char, string>{'2', "abc"});
        mapper.insert(pair<char, string>{'3', "def"});
        mapper.insert(pair<char, string>{'4', "ghi"});
        mapper.insert(pair<char, string>{'5', "jkl"});
        mapper.insert(pair<char, string>{'6', "mno"});
        mapper.insert(pair<char, string>{'7', "pqrs"});
        mapper.insert(pair<char, string>{'8', "tuv"});
        mapper.insert(pair<char, string>{'9', "wxyz"});
    }

    vector<string> letterCombinations(string digits) {
        vector<string> resultSet;
        string entry;
        string keysToHit = mapper[0];
        Solve(digits,entry,resultSet);

        return resultSet;

    }
   
    void Solve(string digits,string& entry, vector<string>& resultSet) {
      

        string stroks = mapper[digits[0]];

        for (int i = 0; i < stroks.length(); i++) {
            



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
    cout << s.computeCombinations(digits);
    
    vector<string> vec = s.letterCombinations(digits);
    for (auto a : vec)
        cout << a << " ";

    return 0;
}

/*
 //234
    int computeCombinations(string digits) {
        int comp = 1;
        for (int i = 0; i < digits.length(); i++) {
            string codePerDigit = mapper[digits[i]];
            comp *= codePerDigit.length();
        }
        return comp;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string codes = mapper[digits[0]];
        for (int i = 0; i < 3; i++)
        {
            string comb;
            comb.push_back(codes[i]);
            result.push_back(comb);
        }

        return result;
    }
*/