#include "../common.h"

// using priority queue
int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int> ranker;
    for (int x : nums)
        ranker.push(x);

    int largestKth;
    while (k)
    {
        largestKth = ranker.top();
        ranker.pop();
        k--;
    }
    return largestKth;
}

//    /***********************/
//    priority_queue<int> pq;
//    for (int x : nums) {
//        pq.push(x);
//    }
//
//    int larg;
//    while (k) {
//        larg = pq.top();
//        pq.pop();
//        k--;
//    }
//    return larg;
//}

int main()
{
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << findKthLargest(nums, 4) << endl;

    return 0;
}
