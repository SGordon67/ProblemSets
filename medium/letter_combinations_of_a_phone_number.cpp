/*
PROBLEM DESCRIPTION
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. 
Return the answer in any order.
A mapping of digits to letters (just like on the telephone buttons). 
Note that 1 does not map to any letters.

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]

Constraints:
0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/
/*
SOLUTION DESCRIPTION
Hard code the definition for each button as a map from char to vector of char.
For each digit:
  Call the generate funcion once for each character that that digit can represent.
  Each function call represents a new resulting string, with the represented character added on to that function calls' result.
  Once I run out of digits to go through, add the resulting string to the results vector.
Return the results vector after all function calls are done.
*/
class Solution {
public:
    map<char, vector<char>> m;
    void subGenerate(vector<string>& v, string s, string rDigits){
        if(rDigits.length() > 0){
            char cd = rDigits[0];
            rDigits.erase(0,1);
            for(auto x : m[cd]){
                subGenerate(v,s+x,rDigits);
            }
        } else v.push_back(s);
    }
    vector<string> letterCombinations(string digits) {
        m['2'] = {'a','b','c'};
        m['3'] = {'d','e','f'};
        m['4'] = {'g','h','i'};
        m['5'] = {'j','k','l'};
        m['6'] = {'m','n','o'};
        m['7'] = {'p','q','r','s'};
        m['8'] = {'t','u','v'};
        m['9'] = {'w','x','y','z'};
        if(digits.length() == 0) return {};
        vector<string> v;
        subGenerate(v, "", digits);
        return v;
    }
};
