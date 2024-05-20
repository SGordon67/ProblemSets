/*
PROBLEM (easy)
You are working in a ball factory where you have n balls numbered from lowLimit up to highLimit inclusive (i.e., n == highLimit - lowLimit + 1), and an infinite number of boxes numbered from 1 to infinity.
Your job at this factory is to put each ball in the box with a number equal to the sum of digits of the ball's number. 
For example, the ball number 321 will be put in the box number 3 + 2 + 1 = 6 and the ball number 10 will be put in the box number 1 + 0 = 1.
Given two integers lowLimit and highLimit, return the number of balls in the box with the most balls.

Example 1:
Input: lowLimit = 1, highLimit = 10
Output: 2
Explanation:
Box Number:  1 2 3 4 5 6 7 8 9 10 11 ...
Ball Count:  2 1 1 1 1 1 1 1 1 0  0  ...
Box 1 has the most number of balls with 2 balls.

Example 2:
Input: lowLimit = 5, highLimit = 15
Output: 2
Explanation:
Box Number:  1 2 3 4 5 6 7 8 9 10 11 ...
Ball Count:  1 1 1 1 2 2 1 1 1 0  0  ...
Boxes 5 and 6 have the most number of balls with 2 balls in each.

Example 3:
Input: lowLimit = 19, highLimit = 28
Output: 2
Explanation:
Box Number:  1 2 3 4 5 6 7 8 9 10 11 12 ...
Ball Count:  0 1 1 1 1 1 1 1 1 2  0  0  ...
Box 10 has the most number of balls with 2 balls.

Constraints:
1 <= lowLimit <= highLimit <= 105
*/
/*
SOLUTION
Create a map that goes from sum to count (integers)
For each value from lowLimit to highLimit:
  Find the sum of the digits, and add 1 to that sums index in the map.
  If that value in the map is the largest seen, update the largest.
Return the largest seen after running through each value.
I use a map to allow for expansion if more values are needed.
an array of a determined size could be used as substitute if the largest value is known.
*/
class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> m;
        int maxBalls = 0;

        for(int i = lowLimit; i <= highLimit; i++){
            int total = 0;
            int num = i;
            while(num > 0){
                total += num % 10;
                num /= 10;
            }
            m[total]++;
            maxBalls = max(maxBalls, m[total]);
        }
        return maxBalls;
    }
};
