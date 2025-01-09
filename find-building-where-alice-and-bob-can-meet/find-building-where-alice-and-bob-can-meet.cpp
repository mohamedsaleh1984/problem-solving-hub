#include "../common.h"

class Solution
{
public:
    vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries)
    {
        vector<int> r;

        for (int i = 0; i < queries.size(); i++)
        {
            if(queries[i][0] == queries[i][1]){
                r.push_back(queries[i][1]);
                continue;    
            }
            
            vector<int> na = getValidMoves(heights, queries[i][0]);
            vector<int> nb = getValidMoves(heights, queries[i][1]);

            int common = getCommon(na, nb);
            r.push_back(common);
        }
       return r;
    }

    int getCommon(vector<int> a, vector<int> b)
    {
        if (a.size() == 0 || b.size() == 0)
            return -1;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int l = 0, alen = a.size();
        int r = 0, blen = b.size();
        int common = -1;
        while (l < alen || r < blen)
        {
            if (a[l] == b[r])
            {
                common = a[l];
                r++;
                l++;
                break;
            }
            else if (a[l] > b[r])
            {
                r++;
            }
            else if (a[l] < b[r])
            {
                l++;
            }
        }
      
        return common;
    }
    vector<int> getValidMoves(vector<int> heights, size_t index)
    {
        int v = heights[index];
        vector<int> vec;
        for (int i = index+1; i < heights.size(); i++)
        {
            if (heights[i] > v)
            {
                vec.push_back(i);
            }
        }
        
        return vec;
    }
};

int main(int argc, char **argv)
{
    vector<int> heights = {6, 4, 8, 5, 2, 7};
    vector<vector<int>> queries = {{0, 1}, {0, 3}, {2, 4}, {3, 4}, {2, 2}};

    Solution s;

    // [2,5,-1,5,2]
    vector<int> vecResult = s.leftmostBuildingQueries(heights, queries);
    printvector(vecResult);

    return 0;
}