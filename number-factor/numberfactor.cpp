#include <iostream>
#include <stack>
#include <vector>
using namespace std;
/*
    Given N, count the number of ways to express N as sum of 1,3 and 4
*/
int waysToGetN(int n ) {
    if (n == 0 || n == 1 || n == 2) // {},{1},{1,1}
        return 1;
    if (n == 3)
        return 2;//{1,1,1}{3}

    int s1 = waysToGetN(n - 1);
    int s2 = waysToGetN(n - 3);
    int s3 = waysToGetN(n - 4);

    return s1+s2+s3;
}


int main()
{
    vector<int> nums = { 1,3,4 };
    int ways;
    cout << waysToGetN(8);

    return 0;
}
 