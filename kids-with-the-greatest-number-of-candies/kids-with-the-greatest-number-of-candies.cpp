#include "../common.h"

// leetcode.com/problems/kids-with-the-greatest-number-of-candies
// 12/24/2024
//  0ms Beats 100.00%

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        // Find the maximum number of candies any kid currently has
        int maxCandies = *std::max_element(candies.begin(), candies.end());

        // Prepare the result vector
        std::vector<bool> result;

        // Determine if each kid can have the greatest candies with the extraCandies
        for (int candy : candies) {
            result.push_back(candy + extraCandies >= maxCandies);
        }

        return result;
    }
};

int main() {
    
    return 0;
}
