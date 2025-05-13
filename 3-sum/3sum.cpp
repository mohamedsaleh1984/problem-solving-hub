#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <string> // getline, string
#include <vector> // vector
#include <map> // map
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> output;

        for (int i = 0; i < nums.size(); i++) {
            int left = i + 1;
            int right = nums.size() - 1;

            if (i > 0 && nums[i] == nums[i - 1]) continue;

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];

                if (currentSum == 0) {
                    output.push_back({ nums[i], nums[left], nums[right] });
                    left++;
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                }
                else if (currentSum > 0) {
                    right--;
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
                else if (currentSum < 0) {
                    left++;
                }
            }
        }

        return output;
    }
};


int main()
{
	Solution s;
	vector<int> vec = {-1,0,1,2,-1,-4};
	s.threeSum(vec);
	return 0;
}
