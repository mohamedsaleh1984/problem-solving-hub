#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int GetKthLargestInUnsorted(vector<int> ll, int kth) {
    sort(ll.begin(), ll.end());
    return ll[kth - 1];
}

vector<int> removeDuplicates(vector<int> vec) {
    sort(vec.begin(), vec.end());
    
    vector<int> newVec;
    return newVec;
}

int GetKthLargestInDuplicatedVector(
    vector<int> ll, int kth) {
    vector<int> noDuplication = removeDuplicates(ll);
    sort(noDuplication.begin(), noDuplication.end());
    return noDuplication[kth - 1];
}

int main()
{
    vector<int> myList{ 7,10,4,3,20,15 };
    cout << GetKthLargestInUnsorted(myList, 3) << endl;
    cout << GetKthLargestInUnsorted(myList, 4) << endl;

    return 0;
}
