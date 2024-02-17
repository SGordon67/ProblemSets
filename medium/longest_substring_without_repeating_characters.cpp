/*
PROBLEM DESCRIPTION
Given a string s, find the length of the longest 
substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Constraints:
0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/
/*
SOLUTION DESCRIPTION
Sliding window solution.
Get rid of simple cases where length of string is 0 or 1.
Window starts at 0.
Loop until the right side of the window reaches the end of the string:
  If next character exists in substring, move left side of window to the right until we remove the duplicate.
  Then move the right side of the window to the right.
Keeping track of the size of the window the entire time, and the maximum size we saw.
Return the maximum after the loop completes.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        if(s.length() == 1) return 1;

        int i = 0;
        int j = 1;

        int currentLength = 1;
        int maxLength = 1;

        map<char, int> m;
        m[s[i]]++;

        while(j < s.length()){
            while(m[s[j]] >= 1){
                m[s[i]]--;
                i++;
                currentLength--;
            }
            m[s[j]]++;
            currentLength++;
            if(currentLength > maxLength) maxLength = currentLength;
            j++;
        }
        return maxLength;
    }
};
