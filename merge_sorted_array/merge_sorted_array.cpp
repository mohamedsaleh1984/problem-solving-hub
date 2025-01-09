#include "../common.h"
struct mergeSortedArrayTestCase
{
    vector<int> nums1;
    int m;
    vector<int> nums2;
    int n;
    vector<int> expectedOutput;

    mergeSortedArrayTestCase(vector<int> nums1, int m, vector<int> nums2, int n, vector<int> expectedOutput)
    {
        this->nums1 = nums1;
        this->nums2 = nums2;
        this->m = m;
        this->n = n;
        this->expectedOutput = expectedOutput;
    }
};

void printOut(vector<int> res);

// https://leetcode.com/problems/merge-sorted-array/
//
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int p1 = 0, p2 = 0;
        int zeroIndex = m;

        while (p2 < nums2.size())
        {

            if (nums1[p1] <= nums2[p2])
            {
                // right place, move left pointer forward
                p1++;
            }
            else
            {
                // right side less than left side
                if (nums2[p2] < nums1[p1])
                {
                    // shift elements one cell
                    int zeroTemp = zeroIndex;
                    while (zeroTemp > p1)
                    {
                        nums1[zeroTemp] = nums1[zeroTemp - 1];
                        zeroTemp--;
                    }
                    zeroIndex++;

                    // place the element from righ to left side
                    nums1[p1] = nums2[p2];
                    // move right side forward
                    p2++;
                    // move left side forward
                    p1++;
                }
                else if (nums1[p1] == 0 && nums2[p2])
                {
                    nums1[zeroIndex] = nums2[p2];
                    p2++;
                    zeroIndex++;
                    p1 = zeroIndex - 1;
                }
            }
        }
    }
};

void runTest(vector<int> &nums1, int m,
             vector<int> nums2, int n,
             vector<int> expectedOutcome)
{
    Solution s;
    s.merge(nums1, m, nums2, n);

    if (expectedOutcome == nums1)
        cout << "✅ Successful" << endl;
    else
    {
        cout << "❌ Failed" << endl;
        cout << "\tYour output is ";
        printOut(nums1);
        printOut(nums2);
        cout << " and expected output is ";
        printOut(expectedOutcome);
        cout << endl;
    }
}

void runTestCases(vector<mergeSortedArrayTestCase> ex)
{
    for (int i = 0; i < ex.size(); i++)
    {
        runTest(ex.at(i).nums1, ex.at(i).m, ex.at(i).nums2, ex.at(i).n, ex.at(i).expectedOutput);
    }
}

int main()
{
    vector<mergeSortedArrayTestCase> vec = {{{1, 2, 3, 0, 0, 0}, 3, {2, 5, 6}, 3, {1, 2, 2, 3, 5, 6}},
                            {{1}, 1, {}, 0, {1}},
                            {{0}, 0, {1}, 1, {1}},
                            {{4, 5, 6, 0, 0, 0}, 3, {1, 2, 3}, 3, {1, 2, 3, 4, 5, 6}}};

    runTestCases(vec);
}

void printOut(vector<int> res)
{
    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i + 1 != res.size())
            cout << ",";
    }
    cout << "]";
}