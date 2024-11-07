#include <iostream>
#include <vector>
using namespace std;

bool isPalindromic(string s) {
	if (s.length() == 0 || s.length() == 1)
		return true;
	if (s[0] != s[s.length() - 1])
		return false;
	return isPalindromic(s.substr(1, s.length() - 2));
}
 

int LongestPalindromicSubStringAux(string s, int left, int right) {
	if (left > right)
		return 0;

	if (left == right)
		return 1;

	int equal = 0;

	if (s[left] == s[right])
	{
		int remaining = right - left - 1;

		if (remaining == LongestPalindromicSubStringAux(s, left + 1, right - 1))
			equal = remaining + 2;
	}
	
	int elimLeft = LongestPalindromicSubStringAux(s, left+1, right);
	int elimRight = LongestPalindromicSubStringAux(s, left, right-1);

	return max(equal, max(elimLeft, elimRight));
}

int LongestPalindromicSubString(string s) {
	return LongestPalindromicSubStringAux(s, 0, s.length() - 1);
}


int main()
{
	string s = "MQADASM";
	cout << LongestPalindromicSubString(s) << endl;

}
