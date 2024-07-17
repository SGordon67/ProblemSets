/*
PROBLEM (medium)
You are given a positive integer n.
A binary string x is valid if all substrings of x of length 2 contain at least one "1".
Return all valid strings with length n, in any order.

Example 1:
Input: n = 3
Output: ["010","011","101","110","111"]
Explanation:
The valid strings of length 3 are: "010", "011", "101", "110", and "111".

Example 2:
Input: n = 1
Output: ["0","1"]
Explanation:
The valid strings of length 1 are: "0" and "1".

Constraints:
1 <= n <= 18
*/
class Solution {
public:
    vector<string> addDigit(string s){
        vector<string> r = {};
        // if its a new string, give both values.
        if(s.length() == 0){
            r.push_back("0");
            r.push_back("1");
            return r;
        }

        // if last value is 0, you cannot have another 0
        if(s[s.length()-1] == '0'){
            r.push_back(s + '1');
        } else{
            r.push_back(s + '0');
            r.push_back(s + '1');
        }

        return r;
    }
    vector<string> validStrings(int n) {
        // add the first digit manually to start it off
        vector<string> res = {};
        res = addDigit("");

        // loop through to add rest of the digits
        while(n > 1){
            vector<string> newRes = {};
            for(int i = 0; i < res.size(); i++){
                // get the possible strings from all current strings
                vector<string> ad = addDigit(res[i]);
                newRes.insert(newRes.end(), ad.begin(), ad.end());
            }
            // replace old values with updated values with +1 length
            // building up to the solution
            res = newRes;
            n--;
        }
        return res;
    }
};
