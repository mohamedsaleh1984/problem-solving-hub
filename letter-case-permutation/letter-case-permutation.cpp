#include "../common.h"

// https://leetcode.com/problems/letter-case-permutation
// 11 ms Beats 21.37%

class Solution
{
private:
    vector<string> vec;
    stack<string> wordsInProcess;

    void toLower(string &s)
    {
        int len = s.length();
        for (int i = 0; i < len; i++)
        {
            if (isalpha(s[i]))
            {
                s[i] = tolower(s[i]);
            }
        }
    }

public:
    vector<string> letterCasePermutation(string s)
    {
        int len = s.length();

        if (len == 0)
            return vec;

        toLower(s);

        bool called = false;

        for (int i = 0; i < len; i++)
        {
            if (isalpha(s[i]))
            {
                called = true;
                letterCasePermutationHelper(s, i);
            }
        }

        if (!called)
        {
            vec.push_back(s);
        }
        else
        {
            while (!wordsInProcess.empty())
            {
                vec.push_back(wordsInProcess.top());
                wordsInProcess.pop();
            }
        }

        return vec;
    }

    vector<string> createInstances(string &s, int index)
    {
        vector<string> vec;
        string w1 = s;
        string w2 = s;
        w2[index] = w2[index] - 32;

        vec.push_back(w1);
        vec.push_back(w2);
        return vec;
    }

    void letterCasePermutationHelper(string &s, int index)
    {
        if (wordsInProcess.empty())
        {
            vector<string> vec = createInstances(s, index);
            wordsInProcess.push(vec[0]);
            wordsInProcess.push(vec[1]);
        }
        else
        {
            vector<vector<string>> vecx;
            while (!wordsInProcess.empty())
            {
                string word = wordsInProcess.top();
                vector<string> vec = createInstances(word, index);
                vecx.push_back(vec);
                wordsInProcess.pop();
            }

            for (int i = 0; i < vecx.size(); i++)
            {
                wordsInProcess.push(vecx[i][0]);
                wordsInProcess.push(vecx[i][1]);
            }
        }
    }
};

int main(int argc, char **argv)
{
    string s = "a1b8c";
    Solution sol;
    vector<string> vec = sol.letterCasePermutation(s);

    for (auto t : vec)
    {
        cout << t << " ";
    }

    return 0;
}
