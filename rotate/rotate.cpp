#include "../common.h"

void rotate(vector<int>& nums, int k) {

    if (nums.size() <= 1 || k <= 0)
        return;

    //init vec with same size
    vector<int> vec(nums.size());
    int size = nums.size();
    //One pass to re-position elements in new vector
    for (int i = 0; i < size; i++) {
        int newPositon = (i + k) % size;
        vec[newPositon] = nums[i];
    }
    //copy from new to source, we can use copy as well
    for (int i = 0; i < size; i++)
        nums[i] = vec[i];

}


int main()
{
    vector<int> nums = { 1,2,3,4,5,6,7 };
    int k = 3;
    rotate(nums, k);

	return 0;
}
