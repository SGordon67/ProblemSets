/*
PROBLEM DESCRIPTION
Given a string s, return true if s is a good string, or false otherwise.
A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).

Example 1:
Input: s = "abacbc"
Output: true
Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.

Example 2:
Input: s = "aaabb"
Output: false
Explanation: The characters that appear in s are 'a' and 'b'.
'a' occurs 3 times while 'b' occurs 2 times, which is not the same number of times.
 
Constraints:
1 <= s.length <= 1000
s consists of lowercase English letters.
*/
/*
SOLUTION DESCRIPTION
Create a map to hold the number of each letter in the string.
Loop through the map and return false if any letter occurs a different number of times.
*/
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        map<char, int> myMap;
        for(int i = 0; i < s.length(); i++){
            myMap[s[i]]++;
        }
        int comp = myMap[s[0]];
        for (auto c = myMap.begin(); c != myMap.end(); c++) {
            if(c->second != comp) return false;
        }
        return true;
    }
};
