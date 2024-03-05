/*
PROBLEM
Given a string s consisting of words and spaces, return the length of the last word in the string.
A word is a maximal substring consisting of non-space characters only.
 
Example 1:
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

Example 2:
Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.

Example 3:
Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.

Constraints:
1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.
*/
/*
SOLUTION
Start from the end of string, iterating toward the beginning.
Note when you see the start of a word.
Count from there until you see a space.
Return that count.
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        bool sw = false;
        int len = 0;
        for(int i = s.length()-1; i >= 0; i--){
            if(s[i] != ' '){
                sw = true;

            }
            if(sw && s[i] == ' ') return len;
            if(sw) len++;

        }
        return len;
    }
};
