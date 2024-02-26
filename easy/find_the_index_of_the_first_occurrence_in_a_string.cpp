/*
PROBLEM DESCRIPTION
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

Constraints:
1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.
*/
/*
SOLUTION DESCRIPTION
If the needle is larger than the haystack, return -1 because the needle can't fit in the haystack.
Loop through the haystack, looking for the first element of needle.
  When you find needle[0], loop forward seeing if it is the full string, if so, return the intdex of the beggining of the string.
If you loop through without finding the full string, return -1.
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() > haystack.length()) return -1;
        for(int i = 0; i <= haystack.length() - needle.length(); i++){
            if(haystack[i] == needle[0]){
                for(int j = i; j < i+needle.length(); j++){
                    if(haystack[j] != needle[j-i]) break;
                    if(j == i+needle.length()-1) return i;
                }
            }
        }
        return -1;
    }
};
