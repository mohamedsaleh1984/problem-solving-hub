
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

/// @brief sort tuple
/// @param a  
/// @param b 
/// @return 
bool sortbysec(const tuple<int, int>& a,const tuple<int, int>& b)
{
    return (get<1>(a) < get<1>(b));
}

int main()
{
	vector<tuple<int, int>> activities;
	activities.push_back({ 0,6 });
	activities.push_back({ 3,4 });
	activities.push_back({ 1,2 });
	activities.push_back({ 5,8 });
	activities.push_back({ 5,6 });
	activities.push_back({ 8,9 });
	 
	sort(activities.begin(), activities.end(), sortbysec);
	
	tuple<int, int> item = activities[0];
	cout << "{" << get<0>(item) << ", " << get<1>(item) << "}\n";
	int end = get<1>(item);
	for (int i = 1; i < activities.size(); i++) {
		tuple<int, int> currentActivity = activities[i];
		if (get<0>(currentActivity) > end) {
			cout << "{" << get<0>(currentActivity) << ", " << get<1>(currentActivity) << "}\n";
			end = get<1>(currentActivity);
		}
	}

}

