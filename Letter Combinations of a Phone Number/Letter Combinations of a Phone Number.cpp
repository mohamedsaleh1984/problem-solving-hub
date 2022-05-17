#include <iostream>
#include <vector>
#include <map>
using namespace std;
//https://leetcode.com/problems/letter-combinations-of-a-phone-number/
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
        vector<string> result;
        if (digits.length() == 0)
            return result;

        if (digits.length() == 1) {
            string chrs = mapper[digits[0]];
            for (int i = 0; i < chrs.length(); i++) {
                string entry(1, chrs[i]);
                result.push_back(entry);
            }
        }

        if (digits.length() == 2) {
            result = product2Digits(mapper[digits[0]], mapper[digits[1]]);
            return result;
        }

        if (digits.length() == 3) {
            result = product3Digits(mapper[digits[0]], mapper[digits[1]], mapper[digits[2]]);
            return result;
        }

        if (digits.length() == 4) {
            result = product4Digits(mapper[digits[0]], mapper[digits[1]], mapper[digits[2]], mapper[digits[3]]);
            return result;
        }


        return result;
    }

    vector<string> product2Digits(string a, string b) {
        vector<string> result;
        for (int i = 0; i < a.length(); i++) {
            string entry = "";
            entry.push_back(a[i]);
            for(int j = 0 ; j < b.length() ; j++){
                entry.push_back(b[j]);
                result.push_back(entry);
                entry.pop_back();
            }
        }
        return result;
    }
    vector<string> product3Digits(string a, string b,string c) {
        vector<string> result;
        for (int i = 0; i < a.length(); i++) {
            string entry = "";
            entry.push_back(a[i]);
            for (int j = 0; j < b.length(); j++) {
                entry.push_back(b[j]);
                for (int k = 0; k < c.length(); k++) {
                    entry.push_back(c[k]);
                    result.push_back(entry);
                    entry.pop_back();
                }
                entry.pop_back();
            }
            entry.pop_back();
        }
        return result;
    }

    vector<string> product4Digits(string a, string b, string c,string d) {
        vector<string> result;
        for (int i = 0; i < a.length(); i++) {
            string entry = "";
            entry.push_back(a[i]);
            for (int j = 0; j < b.length(); j++) {
                entry.push_back(b[j]);
                for (int k = 0; k < c.length(); k++) {
                    entry.push_back(c[k]);
                    for (int t = 0; t < d.length(); t++) {
                        entry.push_back(c[t]);
                        result.push_back(entry);
                        entry.pop_back();
                   }
                    entry.pop_back();
                }
                entry.pop_back();
            }
            entry.pop_back();
        }
        return result;
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

    string digits = "5678";
    Solution s;
    vector<string> vec = s.letterCombinations(digits);
    for (auto a : vec)
        cout << a << " ";

    return 0;
}