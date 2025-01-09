#include "../common.h"

template <class T>
void view(vector<T> vec){
    for(auto x: vec)
        cout << x;
    cout << endl;
}
// https://leetcode.com/problems/string-compression/
// 0 ms Beats 100.00%
class Solution
{
public:
    int compress(vector<char> &chars)
    {
        view(chars);
        // single char return 1
        if (chars.size() == 1)
            return 1;

        unsigned int index = 0;
        unsigned int count = 1;
        unsigned int len = chars.size();
        vector<char> vec;

        while (index < len - 1)
        {
            if (chars[index] == chars[index + 1])
            {
                count++;
            }
            else
            {
                // pushing char a
                vec.push_back(chars[index]);

                string str = to_string(count);
                // check count
                if (count > 1)
                {
                    for (size_t i = 0; i < str.length(); i++)
                    {
                        vec.push_back(str[i]);
                    }
                }
                count = 1;
            }
            index++;
        }

        //
        // pushing char a
        vec.push_back(chars[index]);

        string str = to_string(count);
        // check count
        if (count > 1)
        {
            for (size_t i = 0; i < str.length(); i++)
            {
                vec.push_back(str[i]);
            }
        }

        view(vec);
        //
        for (size_t i = 0; i < vec.size(); i++) {
            chars[i] = vec[i];
        }

        cout << "************************************" << endl;
        return vec.size();
    }
};

int main(int argc, char **argv)
{
    Solution s;

    vector<char> v = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    vector<char> v2 = {'a', 'a'};
    vector<char> v3 = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    vector<char> v4 = {'a'};

    cout << s.compress(v) << endl;
    cout << s.compress(v2) << endl;
    cout << s.compress(v3) << endl;
    cout << s.compress(v4) << endl;

    return 0;
}