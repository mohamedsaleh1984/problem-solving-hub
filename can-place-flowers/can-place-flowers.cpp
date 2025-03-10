#include "../common.h"

// https://leetcode.com/problems/can-place-flowers/
// 12/24/2024
class Solution
{
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        int size = fb.size();
        for (int i = 0; i < size ; i++) {
            // Check if the current plot is empty.
            if (fb[i] == 0) {
                // Check if the left and right plots are empty.
                bool l = (i == 0) || (fb[i - 1] == 0);
                bool r = (i == size - 1) || (fb[i + 1] == 0);
                
             
                if (l && r) {
                    fb[i] = 1;
                    n--;
                }
            }
        }

        return n <= 0;
    }
};

class TestCase
{
private:
    vector<int> _vec = {};
    int _n = 0;
    bool _output;

public:
    TestCase(vector<int> ivec, int in, bool output) : _vec(ivec), _n(in), _output(output) {}

    vector<int>& getV()
    {
        return _vec;
    }

    int getN()
    {
        return _n;
    }
    bool getOutput()
    {
        return _output;
    }
};



void RunTestCase(vector<TestCase> in)
{
    float successRate;
    float passed = 0;
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono;      // nanoseconds, system_clock, seconds

    Solution s;
    bool bResult = false;

    std::cout << "\033[32m";
    cout << "Running Test Cases..." << endl;

    for (size_t i = 0; i < in.size(); i++)
    {
        TestCase testcase = in[i];
    
        bResult = s.canPlaceFlowers(testcase.getV(), testcase.getN());

        sleep_for(nanoseconds(10));
        sleep_until(system_clock::now() + seconds(1));

        if (bResult == testcase.getOutput())
        {
            // green
            std::cout << "\033[32m";
            cout << "Success expected " << testcase.getOutput() << " actual " << bResult << endl;
            passed++;
        }
        else
        {
            // red
            std::cout << "\033[31m";
            cout << "Failed expected " << testcase.getOutput() << " actual " << bResult << endl;
        }
        // default
        std::cout << "\033[0m";
    }

    // blue color
    std::cout << "\033[34m";
    successRate = (passed * ( 100.0/in.size() ));
    cout << "Success rate is " << successRate << "%" << endl;
    // default color
    std::cout << "\033[0m";
}



int main()
{
    vector<TestCase> vectestCase;

    vectestCase.push_back(TestCase({1, 0, 0, 0, 1}, 1, true));
    vectestCase.push_back(TestCase({0, 0, 1, 0, 1}, 1, true));
    vectestCase.push_back(TestCase({1, 0, 0, 0, 1, 0, 0}, 2, true));
    vectestCase.push_back(TestCase({1}, 0, true));
    vectestCase.push_back(TestCase({1}, 1, false));
    vectestCase.push_back(TestCase({0, 1, 0}, 1, false));
    vectestCase.push_back(TestCase({1, 0, 0, 0, 0, 1}, 2, false));

    RunTestCase(vectestCase);

    return 0;
}