/*
PROBLEM
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
A subsequence of a string is a new string that is formed from the original string by deleting 
some (can be none) of the characters without disturbing the relative positions of the remaining characters. 
(i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false

Constraints:
0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.
*/
/*
SOLUTION
I originally went far too complex with a solution, thinking about dynamic programming and how to retrace my steps if we did not find a character.
Then I realized we can just take the first instance of a character because they must be in order anyway.
A simple loop, incrememnting my counter forward as I encounter characters from the subsequence solves this problem.
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int matches = 0;
        for(int i = 0; i < t.length(); i++){
            if(s[matches] == t[i]){
                matches++;
            }
        }
        if(matches == s.length()) return true;
        return false;
    }
};
