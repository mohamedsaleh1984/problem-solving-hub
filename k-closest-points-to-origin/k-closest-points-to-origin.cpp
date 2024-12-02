#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <complex>
#include <string>
#include <tuple>
#include <utility>
using namespace std;

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        map<float, vector<int>> ref = calc(points);
        vector<vector<int>> kPoints = getKPoints(ref, k);
        return kPoints;
    }

    vector<vector<int>> getKPoints(map<float, vector<int>> data, int k)
    {
        vector<vector<int>> points;
        // min
        auto it = data.begin();
        int count = 0;

        while (it != data.end() && count < k)
        {
            points.push_back(it->second);
            count++;
       
            it++;
        }
        return points;
    }

    float distance(vector<int> p1, vector<int> p2)
    {
        float dist = sqrtf(powf(p1[0] - p2[0], 2) + powf(p1[1] - p2[1], 2));
        return dist;
    }

    map<float, vector<int>> calc(vector<vector<int>> &points)
    {
        map<float, vector<int>> data;
        vector<int> origin = {0, 0};

        for (int i = 0; i < points.size(); i++)
        {
            float d = distance(origin, points[i]);

            std::pair<float, vector<int>> __pair = make_pair(d, vector<int>());
            __pair.second.push_back(points[i][0]);
            __pair.second.push_back(points[i][1]);

            data.insert(__pair);
        }
        return data;
    }

    void viewPoints(vector<vector<int>> points)
    {
        for (int i = 0; i < points.size(); i++)
        {
            cout << "(" << points[i][0] << ", " << points[i][1] << ")" << endl;
        }
    }
};

int main(int argc, char **argv)
{
    vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
    int k = 2;
    Solution sol;
    vector<vector<int>> points2 = sol.kClosest(points, k);
    sol.viewPoints(points2);

    return 0;
}