#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    vector<int> change = { 100,50,20 };
    int input = 260;
    vector<int> output(3);

    while (input != 0)
    {
        for (int i = 0; i < change.size(); ++i)
        {
            if (input >= change[i] &&
                (input % change[i] == 0 || find(change.begin()+i,change.end(), input%change[i]) != change.end()))
            {
                int count = input / change[i];
                output[i] = count;
                input = input - (count * change[i]);
            }
            if (input == 0)
                break;
        }
    }


    return 0;
}
