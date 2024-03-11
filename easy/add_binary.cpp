/*
PROBLEM
Given two binary strings a and b, return their sum as a binary string.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"

Constraints:
1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/
/*
SOLUTION
While both strings still have values left to take from, grab the last value from each string, and remove it after each iteration:
  'add' the digits while accounting for the carry bit.
Once at least one string is depleted.
Accounting for the carry bit, append the rest of the remaining string to the front of the result.
Return result.
*/
class Solution {
public:
    string addBinary(string a, string b) {
        string r = "";
        bool carry = false;
        while(a.length() > 0 && b.length() > 0){
            char next;
            if(a[a.length()-1] == '1' && b[b.length()-1] == '1'){
                if(carry){ 
                    next = '1';
                } else {
                    next = '0';
                }
                carry = true;
            } else if(a[a.length()-1] == '1' || b[b.length()-1] == '1'){
                if(carry){ 
                    next = '0';
                    carry = true;
                } else {
                    next = '1';
                    carry = false;
                }
            } else{
                if(carry){ 
                    next = '1';
                } else {
                    next = '0';
                }
                carry = false;
            }
            a.pop_back();
            b.pop_back();
            r = next + r;
        }
        while(a.length() != 0){
            if(carry){
                if(a[a.length()-1] == '1'){
                    r = '0' + r;
                    a.pop_back();
                }else{
                    r = '1' + r;
                    a.pop_back();
                    carry = false;
                }
            } else{
                r = a + r;
                a = "";
            }
        }
        while(b.length() != 0){
            if(carry){
                if(b[b.length()-1] == '1'){
                    r = '0' + r;
                    b.pop_back();
                }else{
                    r = '1' + r;
                    b.pop_back();
                    carry = false;
                }
            } else{
                r = b + r;
                b = "";
            }
        }
        if(a.length() == 0 && b.length() == 0 && carry) r = '1' + r;
        return r;
    }
};
