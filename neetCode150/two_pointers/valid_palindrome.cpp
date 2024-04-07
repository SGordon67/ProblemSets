/*
PROBLEM
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. 
Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.

Constraints:
1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/
/*
SOLUTION
Two pointer approach, one at start, the other at the end of the string.
Repeat until pointers reach eachother:
Move the pointer closer to the center if it is not a valid alphanumeric character. (check both)
If both pointers point to a valid char, compare them.
If they match, continue by moving both pointers toward center.
If they do not match, you can return false since it is not a valid palindrome.
Once both pointers reach the center, you can return true since it makes a valid palindrome.
*/
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() <= 1) return true;

        int i = 0;
        int j = s.length() - 1;

        while(i < j){
            bool comp = true;
            if(!isalnum(s[i])){
                i++;
                comp = false;
            }
            if(!isalnum(s[j])){
                j--;
                comp = false;
            }
            if(comp){
                if(!(tolower(s[i]) == tolower(s[j]))){
                    return false;
                } else{
                    i++;
                    j--;
                }
            }
        }
        return true;
    }
};
