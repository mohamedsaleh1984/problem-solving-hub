#include <iostream>
#include <string>
using namespace std;
/*
	Convert one string to another.
*/
//3 operations
// Insert, replace, delete
/*
	Delete = f(n,n+1) 
	Insert = f(n+1,n)
	Replace = f(n,n)
*/

int ConvertOneStringAux(string s1, int i, string s2, int j);

int ConvertOneStringToAnother(string s1,string s2) {
	return ConvertOneStringAux(s1, 0, s2, 0);
}

int ConvertOneStringAux(string s1, int i, string s2, int j) {
	//In case we reached to the last character in the first string, then we need at least
	// to add the number of ADD operations to add remaining characters in string 2
	if (i == s1.length())
		return s2.length() - j;
	//In case we reached to last character in second string, we need to add all 
	// the number of ADD Operations to match S2 with S1

	if (j == s2.length())
		return s1.length() - i;

	if (s1[i] == s2[j]) {
		return ConvertOneStringAux(s1, i + 1, s2, j + 1);
	}

	int c1 = 1 + ConvertOneStringAux(s1, i + 1, s2, j);//Insertion
	int c2 = 1 + ConvertOneStringAux(s1, i, s2, j + 1);//Delete
	int c3 = 1 + ConvertOneStringAux(s1, i + 1, s2, j + 1);//Replace

	return min(c1, min(c2, c3));
}

int main()
{	
	string s1 = "mohamed";
	string s2 = "mohaaamed";
	cout << ConvertOneStringToAnother(s1, s2);
	return 0;
}
