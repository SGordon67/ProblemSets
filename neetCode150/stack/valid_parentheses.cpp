/*
PROBLEM (easy)
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Constraints:
1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/
/*
SOLUTION
Loop through the string:
  If we see an open parentheses, push onto the stack
  If we see a close parentheses, 
    If stack is empty return false,
    otherwise check to make sure the character we have matches the top of the stack,
    If not then return false.
    Pop the top of the stack.
If you make it through the entire string, return true if stack is empty.
Otherwise return false.
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            } else{
                if(st.empty()) return false;
                switch(st.top()){
                    case '{':
                        if(s[i] != '}') return false;
                        break;
                    case '(':
                        if(s[i] != ')') return false;
                        break;
                    case '[':
                        if(s[i] != ']') return false;
                        break;
                }
                st.pop();
            }
        }
        if(st.empty()) return true;
        return false;
    }
};
