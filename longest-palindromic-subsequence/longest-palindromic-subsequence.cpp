#include "../common.h"

int longestPalindromicSubSequence(string s);
int longestPalindromicSubSequenceAux(string s, int left, int right)
{
	if (left > right)
		return 0;

	if (left == right)
		return 1;

	int IsPal = 0;
	if (s[left] == s[right])
		IsPal = 2 + longestPalindromicSubSequenceAux(s, left + 1, right - 1);

	int elimLeftTakeRight = longestPalindromicSubSequenceAux(s, left + 1, right);
	int elimRightTakeLeft = longestPalindromicSubSequenceAux(s, left, right - 1);

	return max(IsPal, max(elimLeftTakeRight, elimRightTakeLeft));
}

int longestPalindromicSubSequence(string s)
{
	return longestPalindromicSubSequenceAux(s, 0, s.length() - 1);
}

int main()
{
	string s = "ELRMENMET"; // 5 EMEME
	string s2 = "AMEEWMEA"; // 6 AMEEMA
	cout << longestPalindromicSubSequence(s) << endl;
	cout << longestPalindromicSubSequence(s2) << endl;
	// cout << isPalindromic("AA") << endl;

	return 0;
}
