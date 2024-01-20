/*
PROBLEM DESCRIPTION
Given an integer n, return true if it is a power of three. Otherwise, return false.
An integer n is a power of three, if there exists an integer x such that n == 3x.

Example 1:
Input: n = 27
Output: true
Explanation: 27 = 33

Example 2:
Input: n = 0
Output: false
Explanation: There is no x where 3x = 0.

Example 3:
Input: n = -1
Output: false
Explanation: There is no x where 3x = (-1).
 
Constraints:
-231 <= n <= 231 - 1
*/

/*
SOLUTION DESCRIPTION
Loop through each power of three.
Once you reach n:
  return true if equal
  return false if passed n
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        for(int i = 0; i < n; i++){
            double x = pow(3, i);
            if(x == n) return true;
            if(x > n) return false;
        }
        return false;
    }
};
