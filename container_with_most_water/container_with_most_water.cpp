#include <iostream>
#include <vector>
using namespace std;
//https://leetcode.com/problems/container-with-most-water
int maxArea(vector<int>& height) {
    int left = 0, right = height.size()-1;
        int iMax = 0;
    
        while(left < right){
            int area = (right-left) * min(height[left],height[right]);
            iMax = max(iMax,area);
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        
        return iMax;
}

int main()
{
	vector<int> heights{ 1,8,6,2,5,4,8,3,7 };
    cout << maxArea(heights);

	return 0;
}
