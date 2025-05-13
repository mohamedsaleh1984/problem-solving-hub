#include "../common.h"

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n == 0)
            return false;

        while (n % 3 == 0)
            n = n / 3;
        return n == 1;
    }
};

int main()
{
    Solution s = Solution();
    cout << s.isPowerOfTwo(3) << endl;
    return 0;
}
