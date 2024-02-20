/*
PROBLEM DESCRIPTION
Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"

Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters.
*/
/*
SOLUTION DESCRIPTION
For every index i in the given string s:
  Test if there is an odd or even length substring palindrome with index i in the center (i and i+1 in the center for even length).
Do this by expanding outward on both sides of index i until you reach the end of the string on either side, or until the characters on each side don't match and are therefore not palindromic.
Return the longest palindromic substring you find.
*/
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() == 0) return "";
        string lPal = "";

        for(int i = 0; i < s.length(); i++){
            // odd length case
            int a = i;
            int b = i;
            while(a >= 0 && b < s.length() && s[a] == s[b]){
                a--;
                b++;
            }
            string oddPal = s.substr(a+1, ((b-1)-(a+1)+1));
            if(oddPal.length() > lPal.length()) lPal = oddPal;

            // even case
            a = i;
            b = i+1;
            while(a >= 0 && b < s.length() && s[a] == s[b]){
                a--;
                b++;
            }
            string evenPal = s.substr(a+1, ((b-1)-(a+1)+1));
            if(evenPal.length() > lPal.length()) lPal = evenPal;
        }
        return lPal;
    }
};
