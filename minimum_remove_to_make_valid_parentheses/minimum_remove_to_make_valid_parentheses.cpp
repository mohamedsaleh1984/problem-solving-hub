#include <iostream>
#include <stack>
#include <vector>
using namespace std;

string minRemoveToMakeValid(string s) {

    std::vector<char> v(s.begin(), s.end());
    stack<int> stkIndex;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] == '(')
        {
            stkIndex.push(i);
        }
        else if (v[i] == ')' && stkIndex.empty())
        {
            stkIndex.pop();
        }
        else if (v[i] == ')') {
            v[i] = '\0';
        }
    }

    while (!stkIndex.empty()) {
        int i = stkIndex.top();
        stkIndex.pop();
        v[i] = '\0';
    }

std::string strResult(v.begin(), v.end());


return strResult;
    }

int main()
{
	return 0;
}