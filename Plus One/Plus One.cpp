#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/559/
//TODO:solve
vector<int> plusOne(vector<int>& digits) {
    if (digits[digits.size() - 1] < 9) {
        digits[digits.size() - 1]++;
        return digits;
    }
    else {
        digits.push_back(0);
        

    }
   
  

    return vec;
}

void printOut(vector<int> vec) {
    for (auto x : vec)
        cout << x << " ";
    cout << endl;
}
int main()
{
	vector<int> digits = { 4, 3, 2, 1 };
    plusOne(digits);
	vector<int> digits2 = { 1, 2, 3 };

	return 0;
}