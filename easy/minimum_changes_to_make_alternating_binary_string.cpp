/*
PROBLEM DESCRIPTION
You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa.
The string is called alternating if no two adjacent characters are equal. For example, the string "010" is alternating, while the string "0100" is not.
Return the minimum number of operations needed to make s alternating.

Example 1:
Input: s = "0100"
Output: 1
Explanation: If you change the last character to '1', s will be "0101", which is alternating.

Example 2:
Input: s = "10"
Output: 0
Explanation: s is already alternating.

Example 3:
Input: s = "1111"
Output: 2
Explanation: You need two operations to reach "0101" or "1010".

Constraints:
1 <= s.length <= 104
s[i] is either '0' or '1'.
*/
/*
SOLUTION DESCRIPTION
Solution takes advantage of the fact that there are only two possible strings in which it is alternating:
  A string starting with zero, and a string starting with 1.
My solution is to tally up points toward each one of these possible strings, to see how the current string matches with each possiblity.
Loop through the string, add a point to either tally depending on the current character in the string.
Whichever string has the higher score at the end is the one we go with.
The number of changes required is the length of the string minus the number of points that that string earned.
*/
class Solution {
public:
    int minOperations(string s) {

        int evenZero = 0;
        int oddZero = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '0'){
                if(i % 2 == 0){
                    evenZero++;
                } else oddZero++;
            } else{
                if(i % 2 == 0){
                    oddZero++;
                } else evenZero++;
            }
        }
        return s.length() - max(evenZero, oddZero);
    }
};
