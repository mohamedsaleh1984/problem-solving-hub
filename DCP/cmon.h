#pragma once
#include <iostream>
#include <climits>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <stack>
#include <vector>
#include <set>
#include <string>
#include <list>
#include <cmath>
#include <stdlib.h>     /* srand, rand */
using namespace std;

template <class T>
void dump(vector<T> vec) {
	for_each(vec.begin(), vec.end(), [](T& elem) {
		cout << elem << " ";
	});
}
template <class T>
void dump(vector< vector<T>> vec) {
	for_each(vec.begin(), vec.end(), [](T& elem) {
		dump(elem);
		cout << "\n";
	});
}