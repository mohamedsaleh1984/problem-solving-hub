#include <iostream>
#include <string>
#include <vector>
using namespace std;
//https://leetcode.com/problems/binary-gap/submissions/
//ToDo:fix
std::string toBinary(unsigned long long number) {
	string result = "";

	while (number != 0) {
		if (number % 2 == 0)
			result += '0';
		else
			result += '1';
		number = number / 2;
	}

	reverse(result.begin(), result.end());
	return result;
}

int GetGap(string binaryRep) {
	int  ptr = 0, maxGap = 0, counter = 0;
	int len = binaryRep.length();

	while (ptr < len) {
		if (binaryRep[ptr] == '1')
		{
			counter = 0;
			ptr++;
			while (binaryRep[ptr] == '0' && ptr < len) {
				counter++;
				ptr++;
			}
			if (ptr <= len - 1 && binaryRep[ptr] == '1') {
				maxGap = max(maxGap, counter);
			}
		}
		else { ptr++; }
	}

	return maxGap;
}
int solution(unsigned long long N) {
	std::string binaryRep = toBinary(N);
	return GetGap(binaryRep);
}

void testBinaryConversion(vector<unsigned long long> v) {
	for (unsigned long long x : v) {
		cout << x << " " << toBinary(x) << endl;
	}
}

void testSolution(vector<unsigned long long> v) {
	for (unsigned long long x : v) {
		string  bin = toBinary(x);
		cout << x << "    " << bin << "   " << solution(x) << endl;
	}
}

int main()
{
	vector<unsigned long long > vec = { 51712,1162, 328,19, 5,6,47589,8053063730,15,9,1073741825,1610612737,6291457,20 };
	testSolution(vec);
	//cout << solution(328) << endl;
	return 0;
}
