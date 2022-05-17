#include <iostream>
#include <vector>
using namespace std;

int longestCommonSubSequenceAux(string s1, int i1, string s2, int i2);

int lengthlongestCommonSubSequence(string s1, string s2) {
	return longestCommonSubSequenceAux(s1,0 ,s2, 0);
}

/*

*/
int longestCommonSubSequenceAux(string s1, int i1, string s2, int i2) {
	if (i1 >= s1.length() || i2 >= s2.length())
		return 0;
	int equal = 0;
	if (s1[i1] == s2[i2])
		equal =  1 + longestCommonSubSequenceAux(s1, i1 + 1, s2, i2 + 1);

	int withDelLeft = longestCommonSubSequenceAux(s1, i1 + 1, s2, i2 );
	int withDelRight = longestCommonSubSequenceAux(s1, i1 , s2, i2+1);
		
	return max(equal, max(withDelLeft, withDelRight));
}


int main()
{
	string s1 = "elephant";
	string s2 = "eretpat";
	cout << lengthlongestCommonSubSequence(s1, s2) << endl;


	vector<char> common = {};
	common = commonSubSequece(s1, s2);

	for (auto item : common) {
		cout << item << " ";
	}





	return 0;
}
