/*
PROBLEM (medium)
You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' if the ith box is empty, and '1' if it contains one ball.
In one operation, you can move one ball from a box to an adjacent box. Box i is adjacent to box j if abs(i - j) == 1. Note that after doing so, there may be more than one ball in some boxes.
Return an array answer of size n, where answer[i] is the minimum number of operations needed to move all the balls to the ith box.
Each answer[i] is calculated considering the initial state of the boxes.

Example 1:
Input: boxes = "110"
Output: [1,1,3]
Explanation: The answer for each box is as follows:
1) First box: you will have to move one ball from the second box to the first box in one operation.
2) Second box: you will have to move one ball from the first box to the second box in one operation.
3) Third box: you will have to move one ball from the first box to the third box in two operations, and move one ball from the second box to the third box in one operation.

Example 2:
Input: boxes = "001011"
Output: [11,8,5,4,3,4]

Constraints:
n == boxes.length
1 <= n <= 2000
boxes[i] is either '0' or '1'.
*/
class Solution {
public:
    vector<int> minOperations(string boxes) {
        // get the value for the 0th place by adding up the indices of each ball at the start
        int numBalls = 0;
        int totalDistToZero = 0;
        // keep track of how many balls we passed for each index in leftOf vector
        vector<int> leftOf(boxes.length(), 0);
        for(int i = 1; i <= boxes.length(); i++){
            if(boxes[i-1] == '1'){
                numBalls++;
                totalDistToZero += i-1;
            }
            if(i < boxes.length()) leftOf[i] = numBalls;
        }
        // if last box has a ball or not, update last index of leftOf accordingly
        boxes[boxes.length()-1] == '1' ? leftOf[leftOf.size()-1] = numBalls - 1 : leftOf[leftOf.size()-1] = numBalls;

        // 
        vector<int> ans(boxes.length(), 0);
        ans[0] = totalDistToZero;
        for(int i = 1; i < ans.size(); i++){
            // balls to the left get further away
            // balls on the right get closer (total balls - balls we passed)
            ans[i] = ans[i-1] + leftOf[i] - (numBalls - leftOf[i]);
        }
        return ans;
    }
};
