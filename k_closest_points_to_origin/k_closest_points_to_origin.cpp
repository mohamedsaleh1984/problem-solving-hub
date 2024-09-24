#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
using namespace std;


typedef std::vector<int> ivec;
typedef std::multimap<float, ivec>::iterator disIterator;

vector<ivec> kClosest2(vector<ivec>& points, int k) {
	priority_queue<pair<int, ivec>> p;
	for (int i = 0; i < points.size(); i++)
	{
		int dis = points[i][0] * points[i][0] + points[i][1] * points[i][1];
		p.push({ dis,{points[i][0],points[i][1]} });
		if (p.size() > k)
			p.pop();
	}

	vector<vector<int>> v;
	while (p.size() > 0)
	{
		v.push_back(p.top().second);
		p.pop();
	}
	return v;
}
 

vector<ivec> kClosest(vector<ivec>& points, int k) {
	vector<ivec> final_result;
	priority_queue<float> ranker;
	multimap<float, ivec>  mapper;

	for (ivec vec : points) {
		float distanceToOrigin = (float )sqrtf(powf(0 - vec[0], 2) + powf(0 - vec[1], 2));
		ranker.push(distanceToOrigin);
		mapper.insert(std::make_pair<float&,ivec&>(distanceToOrigin, vec));
	}

	stack<float> stk;
	while (!ranker.empty()) {
		stk.push(ranker.top());
		ranker.pop();
	}

	while (!stk.empty()) {
		float pointDistance = stk.top();
		//cout << "Point " << i << " distance is  " << pointDistance << " \n";
		stk.pop();
		int i = 1;
		std::pair<disIterator, disIterator> result = mapper.equal_range(pointDistance);
		for (disIterator it = result.first; it != result.second; it++)
		{
			cout << i << " === " << endl;
			vector<int> second = it->second;
			std::cout << "{" << second[0] << "," << second[1] << "}" << endl;
			++i;
			final_result.push_back(it->second);
		}
	}
	return final_result;
}


int main()
{
	//vector<vector<int>>  points = { {1, 3},{-2, -2} };
	vector<ivec>  points = { {0, 1},{1, 0} };
	vector<ivec> result = kClosest(points, 2);
	for (vector<int> item : result)
		cout << "{" << item[0] << "," << item[1] << "}" << endl;
	result.clear();
}