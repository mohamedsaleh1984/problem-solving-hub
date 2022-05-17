#include <iostream>
#include <stack>
#include <map>
#include <utility>
using namespace std;

int gridTravelUsingRec(int rows, int cols) {
	if (rows == 1 && cols == 1) return 1;
	if (rows == 0 || cols == 0) return 0;
	return gridTravelUsingRec(rows, cols - 1) + gridTravelUsingRec(rows - 1, cols);
}

int gridTravelUsingDP(	int rows,
						int cols,
						std::map<std::pair<int, int>, int> memo) 
{
	pair<int, int> key = make_pair(rows, cols);

	if (memo[key] != 0) {
		cout << memo[key] << " ";
		return memo[key];
	}	

	if (rows == 1 && cols == 1) return 1;
	if (rows == 0 || cols == 0) return 0;


	int p1 = gridTravelUsingDP(rows - 1, cols, memo);
	int p2 = gridTravelUsingDP(rows, cols - 1, memo);
	memo[key] = p1 + p2;
	return memo[key];
}

typedef std::pair<int, int> gridPair;

int main()
{

	//cout << gridTravelUsingRec(1, 1) << endl;//1
	//cout << gridTravelUsingRec(2, 3) << endl;//3
	//cout << gridTravelUsingRec(3, 2) << endl;//3
	//cout << gridTravelUsingRec(3, 3) << endl;//6
	//cout << gridTravelUsingRec(18, 18) << endl; //2333606220

	std::map<std::pair<int, int>, int> memo;
	//cout << gridTravelUsingDP(1, 1, memo) << endl;
	//memo = {};
	//cout << gridTravelUsingDP(2, 3, memo) << endl;
	//memo = {};
	//cout << gridTravelUsingDP(3, 2, memo) << endl;
	//memo = {};
	//cout << gridTravelUsingDP(3, 3, memo) << endl;
	//memo = {};
	cout << gridTravelUsingDP(18, 18, memo) << endl;

	//memo[make_pair(1, 2)] = 10;
	//cout << memo[make_pair(1, 2)];
	return 0;
}

