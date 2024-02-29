/*
PROBLEM DESCRIPTION
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]

Constraints:
1 <= n <= 8
*/
/*
SOLUTION DESCRIPTION
Return simple case of n == 1.
Start by opening one paretheses.
Do both of two options as long as they are available (in separate function calls to cover optoins):
  1. Open another parentheses until you hit quota (n open parentheses).
  2. close existing paretheses if there is still an open one to close.
Once you close the last parentheses, add the result to the vector.
Return the vector at the end.
*/
class Solution {
public:
    void subGenerate(vector<string>& v, string a, int openLeft, int closeLeft){
        if(openLeft > 0){
            subGenerate(v, a + '(', openLeft-1, closeLeft+1);
        }
        if(closeLeft > 0){
            subGenerate(v, a + ')', openLeft, closeLeft-1);
        }
        if(openLeft == 0 && closeLeft == 0){
            v.push_back(a);
        }
    }
    vector<string> generateParenthesis(int n) {
        if(n == 1) return {"()"};

        vector<string> v = {};
        subGenerate(v, "", n,0);
        return v;
    }
};
