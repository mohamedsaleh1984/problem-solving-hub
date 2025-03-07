#include "../common.h"

/*
You are given a string S of length N consisting of characters 'a' and 'b' with additional empty gaps represented
by '?'. Your task is to replace every such gap with either an 'a' character or a 'b' character so that the
longest fragment of S, consisting only of 'a' characters or 'b' characters, is as short as possible.
For example,

for S = "aa??bbb", if you replace "??" with "aa",
the longest fragment consisting of equal characters will have length 4: "aaaabbb". You can obtain a better result by replacing "??" with "ba", resulting in "aababbb".
Then the longest fragment consisting of equal characters will have length 3.

Write a function:
	int solution(string &S);

that, given a string S of length N, returns the minimum possible length of the longest fragment 
of S consisting of equal characters after replacing all "?" characters with letters.
Examples:

1. Given S = "aa??bbb", your function should return 3, as explained above.
2. Given S = "a?b?aa?b?a", your function should return 2.
Question marks can be replaced in the following way: "aabbaabbaa".
3. Given S = "??b??", your function should return 1.
4. Given S = "aa?b?aa", your function should return 3.

Write an efficient algorithm for the following assumptions:
string S consists only of the following characters: "a", "b" and/or "?";
N is an integer within the range [1..100,000].
*/
 

pair<string, int> minimizeLongestFragment(string S) {
    int N = S.length();
    
    // First pass: Fill in the gaps
    for (int i = 0; i < N; ++i) {
        if (S[i] == '?') {
            if (i == 0 || S[i - 1] == '?') {
                S[i] = 'a';  // If it's the first character or previous is '?', use 'a'
            } else {
                // Alternate between 'a' and 'b'
                S[i] = (S[i - 1] == 'a') ? 'b' : 'a';
            }
        }
    }
    cout << S << endl << endl;
    // Now that we have filled the string, let's calculate the longest fragment
    int longest = 1;
    int current_length = 1;
    
    for (int i = 1; i < N; ++i) {
        if (S[i] == S[i - 1]) {
            current_length++;
        } else {
            longest = max(longest, current_length);
            current_length = 1;
        }
    }
    
    // Check the last fragment
    longest = max(longest, current_length);
    
    return {S, longest};
}

int main() {
    string S = "aa??bb";
    
    auto result = minimizeLongestFragment(S);
    
    cout << "Modified String: " << result.first << endl;
    cout << "Length of Longest Fragment: " << result.second << endl;
    
    return 0;
}
