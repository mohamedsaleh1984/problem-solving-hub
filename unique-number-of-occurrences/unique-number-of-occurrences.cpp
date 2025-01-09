#include "../common.h"

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        map<int, int> occur;

        for (int i = 0; i < arr.size(); i++)
        {
            if (occur.count(arr[i]))
            {
                occur[arr[i]]++;
            }
            else
            {
                occur[arr[i]] = 1;
            }
        }

        int msize = occur.size();
        set<int> s;
        map<int, int>::iterator it = occur.begin();
        while (it != occur.end())
        {
            s.insert(it->second);
            it++;
        }

        int ssize = s.size();

        return ssize == msize;
    }
};

int main(int argc, char **argv)
{
    vector<int> vec = {1, 2, 2, 1, 1, 3};
    Solution s;
    cout << s.uniqueOccurrences(vec) << endl;

    return 0;
}
