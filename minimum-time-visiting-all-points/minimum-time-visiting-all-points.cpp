
//https://leetcode.com/problems/minimum-time-visiting-all-points/
//0ms Beats 100.00%

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int x1,y1, res= 0;
        x1 = points[0][0];
        y1 = points[0][1];

        for(int i = 1 ; i < points.size() ; i++){
            int x2,y2;
            x2 = points[i][0];
            y2 = points[i][1];

            // max between steps in x direction or y direction
            res += max(abs(y2-y1), abs(x2-x1));
            
            x1 = points[i][0];
            y1 = points[i][1];
        }
        return res;
    }
};
