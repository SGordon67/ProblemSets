/*
PROBLEM DESCRIPTION
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Constraints:
1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
(My solution does not depend on alphanumeric characters for the solution.)
*/
/*
SOLUTION
For each value in one string:
  Remove that value from each string.
  If the value is not found in the other string, then it is not an anagram.
If you make it  all the way through, and both strings are empty, then it is an anagram.
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        while(s.size() != 0){
            bool found = false;
            for(int i = 0; i < t.size(); i++){
                if(s[0] == t[i]){
                    s.erase(0, 1);
                    t.erase(i, 1);
                    found = true;
                    break;
                }
            }
            if(!found) return false;
        }
        return true;
    }
};
