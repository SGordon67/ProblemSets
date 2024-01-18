/*
PROBLEM DESCRIPTION
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 
Constraints:
1 <= n <= 45
*/
/*
SOLUTION DESCRIPTION
Set the value of the first two steps to one, since there is only one way to reach those steps.
Then starting at step 3 (0 indexed) set the value of the stair to the value of the two previous steps combined.
  This works since you can reach you current step in two ways, either a single or double step.
  Since those steps follow the same logic, you can add them all the way up to n.
*/
class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) return 1;
        if(n == 1) return 1;
        int ppStair = 1;
        int pStair = 1;
        int currentStair = 0;
        for(int i = 2; i <= n; i++){
            currentStair = (pStair + ppStair);
            ppStair = pStair;
            pStair = currentStair;
        }
        return currentStair;
    }
};
