#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int getMinimumDays(vector<int> parcels) {
    int days = 0;
    if (parcels.size() == 0)
        return 0;

    if (parcels.size() == 1)
        return 1;

    int MaxNum = INT_MAX;
    int inputSet = parcels.size();
    while (true) {
        sort(parcels.begin(), parcels.end());
        int MinNum = parcels[0];
        if (MinNum == MaxNum)
            break;

        int toIgnoreInNextCycle = 0;
        for (int i = 0; i < inputSet; i++) {
            if (parcels[i] == INT_MAX)
                continue;
            else if (parcels[i] - MinNum == 0) {
                parcels[i] = MaxNum;
                toIgnoreInNextCycle++;
            }
            else
            {
                parcels[i] -= MinNum;
            }
        }
        days++;
        inputSet = inputSet - toIgnoreInNextCycle;
    }
    return days;
}


int main()
{
    vector<int> parcels{ 2,3,4,3,3};
    cout << getMinimumDays(parcels) << endl;

    return 0;
}
 