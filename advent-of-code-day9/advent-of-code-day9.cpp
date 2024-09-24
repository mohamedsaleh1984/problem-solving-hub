
#include <iostream>
#include <stack>
#include <queue>
#include <typeinfo>
using namespace std;
//TODO: Continue Avent of Code 2020 Day 9
bool IsThereTwoNumbersSumEqualN(vector<int> vec, int n) {
	bool result;
	for (int elem : vec)
	{
		if (elem > n) {
			int sub = elem - n;
			if (find(vec.begin(), vec.end(), sub) != vec.end() && sub != elem) {
				cout << sub << " " << elem << " ";
				return true;
			}
		}
	}
	return false;
}
void view(vector<int> ss) {
	for (int x : ss)
		cout << x << " ";
	cout << endl;
}

bool isValid(vector<int> vec, int num, int window) {

	for (int i = 0; i < vec.size() - window; i++) {
		vector<int> temp(window);
		std::copy(vec.begin() + i, vec.begin() + i + window, temp.begin());


	}


	return false;
}



int main()
{
	vector<int> input = { 35,20,15,25,47,40,62,55,65 };
	int window = 5;
	isValid(input, 2, 5);
	//cout << IsThereTwoNumbersSumEqualN(input, 40);

	return 0;
}