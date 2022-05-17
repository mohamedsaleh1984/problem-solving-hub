#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
/*
	Problem Statememt: Find minimum number of coins to represent a value.
*/
int Coins(int value, vector<int> denominantions) {
	int numberOfCoins = 0;
	for (int i = denominantions.size() - 1; i >= 0; ) {
		if (value >= denominantions[i] && value != 0) //Which is MAXIMUM coin we can get at the momment
		{
			value = value - denominantions[i];
			numberOfCoins++;
		}
		else {
			i--;
		}
		if (value == 0)
			break;
	}
	if (value == 0)
	{
		cout << "I Made it :)" << endl;
		cout << "I Made it :D" << endl;
	}
	else {
		cout << "No avaliable denominations " << endl;
		return -1;
	}

	return numberOfCoins;
}


int main()
{
	vector<int> denominations{ 1,2,5,10,20,50,100,500,1000 };
	cout << Coins(121, denominations) << endl;
	return 0;
}
