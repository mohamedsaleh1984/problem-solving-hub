#include "../common.h"

class Solution
{
public:
    bool isPowerOfFour(int n)
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
    cout << s.isPowerOfFour(16) << endl;
    return 0;
}
