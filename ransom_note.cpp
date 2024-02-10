/*
PROBLEM DESCRIPTION
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
Each letter in magazine can only be used once in ransomNote.

Example 1:
Input: ransomNote = "a", magazine = "b"
Output: false

Example 2:
Input: ransomNote = "aa", magazine = "ab"
Output: false

Example 3:
Input: ransomNote = "aa", magazine = "aab"
Output: true

Constraints:
1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters.
*/
/*
SOLUTION DESCRIPTION
Create a map of characters to int to keep note of how many times each letter appears in the given magazine.
Increment the value of each given character in the magazine.
Then loop throught the ransom note, this time decrementing the value for each character.
If you decrement past 0, this means the letter you need isn't available in the magazine, return false.
If you make it through the loop without decrementing to a negative number, return true.
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> m;
        for(int i = 0; i < magazine.length(); i++){
            m[magazine[i]]++;
        }
        for(int i = 0; i < ransomNote.length(); i++){
            m[ransomNote[i]]--;
        }
        for(int i = 0; i < ransomNote.length(); i++){
            if(m[ransomNote[i]] < 0) return false;
        }
        return true;
    }
};
