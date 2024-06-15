/*
PROBLEM (hard)
Given a string s, return whether s is a valid number.

For example, all the following are valid numbers: 
"2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789", 
while the following are not valid numbers: 
"abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53".

Formally, a valid number is defined using one of the following definitions:
An integer number followed by an optional exponent.
A decimal number followed by an optional exponent.
An integer number is defined with an optional sign '-' or '+' followed by digits.

A decimal number is defined with an optional sign '-' or '+' followed by one of the following definitions:
Digits followed by a dot '.'.
Digits followed by a dot '.' followed by digits.
A dot '.' followed by digits.
An exponent is defined with an exponent notation 'e' or 'E' followed by an integer number.

The digits are defined as one or more digits.

Example 1:
Input: s = "0"
Output: true

Example 2:
Input: s = "e"
Output: false

Example 3:
Input: s = "."
Output: false

Constraints:
1 <= s.length <= 20
s consists of only English letters (both uppercase and lowercase), digits (0-9), plus '+', minus '-', or dot '.'.
*/
class Solution {
public:
    bool isNumber(string s) {
        bool isNumber = true;
        
        bool isPN = true;
        bool isN = true;
        bool isD = true;
        bool isE = false;
        bool seenE = false;
        bool seenD = false;
        bool isSpace = true;
        bool seenSpace = false;
        
        bool needsNum = true;
        bool seenNum = false;
        
        bool lastSpace = false;
        
        for (char const &c: s) {
            switch(c){
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    seenNum = true;
                    needsNum = false;
                    if(isN == false) isNumber = false;
                    isPN = false;
                    isN = true;
                    isD = true;
                    isE = true;
                    isSpace = true;
                    lastSpace = false;
                    break;
                case '.':
                    if(seenD == true || isD == false || seenE == true) isNumber = false;
                    isPN = false;
                    isN = true;
                    isD = false;
                    isE = true;
                    seenD = true;
                    isSpace = true;
                    lastSpace = false;
                    break;
                case 'e':
                    needsNum = true;
                    if(seenE == true || isE == false || seenNum == false) isNumber = false;
                    isPN = true;
                    isD = false;
                    seenE = true;
                    lastSpace = false;
                    break;
                case '-':
                case '+':
                    needsNum = true;
                    if(isPN == false) isNumber = false;
                    isPN = false;
                    isE = false;
                    isSpace = false;
                    lastSpace = false;
                    break;
                case ' ':
                    if(isSpace == false) isNumber = false;
                    if(lastSpace == true){
                        isSpace = true;
                        if(seenNum == true || seenD == true) {
                            isN = false;
                            isD = false;
                        }
                        break;
                    }
                    if(seenSpace == true && isSpace == false) isNumber = false;
                    seenSpace = true;
                    if(seenNum == true || seenD == true) {
                        isN = false;
                        isD = false;
                    }
                    lastSpace = true;
                    break;
                default:
                    return false;
                    break;
            }
        }
        if(needsNum == false) return isNumber;
        return false;
    }
};
