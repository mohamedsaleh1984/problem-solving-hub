#include <iostream>
#include <vector> 
using namespace std;

int binary_search(std::vector<int> arr, int target) {
    int result = -1;
    int l = 0, r = arr.size() - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        int elem = arr[mid];

        if (elem == target)
        {
            result = mid;
            break;
        }
        else if (elem > target) {
            
           r= mid - 1;
        }
        else if (elem < target) {
            l = mid+1;
        }
    }


    return result;
}

int main()
{
	vector<int> arr = { 1,2,6,8,9,10,12,15 };
    cout << binary_search(arr, 50) << endl;

	return 0;
}
 