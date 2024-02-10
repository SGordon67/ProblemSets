/*
PROBLEM DESCRIPTION
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

Example 1:
Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10

Example 2:
Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
 
Constraints:
0 <= n <= 105
*/
/*
SOLUTION DESCRIPTION
create a vector to store results.
from i = 0 to n, for each value of i:
  keep dividing by 2 until that value of i = 0.
  keep track of how many times the remainder is 1.
  add the number of remainders to the results vector.
*/
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> b;
        for(int i = 0; i <= n; i++){
            int t = i;
            int bits = 0;
            while(t > 0){
                if(t % 2) bits++;
                t /= 2;
            }
            b.push_back(bits);
        }
        return b;
    }
};
