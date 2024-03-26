/*
PROBLEM
Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.

Example 1:
Input: s = "00110110", k = 2
Output: true
Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.

Example 2:
Input: s = "0110", k = 1
Output: true
Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring.

Example 3:
Input: s = "0110", k = 2
Output: false
Explanation: The binary code "00" is of length 2 and does not exist in the array.

Constraints:
1 <= s.length <= 5 * 105
s[i] is either '0' or '1'.
1 <= k <= 20
*/
/*
SOLUTION
Essentially use a sliding window.
Calculate the expected number of binary codes, which is pow(2, k) since we're using binary.
keep track of the number of different binary codes you see using an unordered set.
If the set reaches your expected number, return true.
If you reach the end of the string before reaching that number, return false.
*/
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k > s.length()) return false;

        int goalNum = pow(2, k);
        unordered_set<string> m = {};

        for(int i = 0; i <= s.length() - k; i++){
            m.insert(s.substr(i, k));
            if(m.size() == goalNum) return true;
        }
        return false;
    }
};
