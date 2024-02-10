/*
PROBLEM DESCRIPTION
You are given an array nums of positive integers. In one operation, you can choose any number from nums and reduce it to exactly half the number. (Note that you may choose this reduced number in future operations.)
Return the minimum number of operations to reduce the sum of nums by at least half.

Example 1:
Input: nums = [5,19,8,1]
Output: 3
Explanation: The initial sum of nums is equal to 5 + 19 + 8 + 1 = 33.
The following is one of the ways to reduce the sum by at least half:
Pick the number 19 and reduce it to 9.5.
Pick the number 9.5 and reduce it to 4.75.
Pick the number 8 and reduce it to 4.
The final array is [5, 4.75, 4, 1] with a total sum of 5 + 4.75 + 4 + 1 = 14.75. 
The sum of nums has been reduced by 33 - 14.75 = 18.25, which is at least half of the initial sum, 18.25 >= 33/2 = 16.5.
Overall, 3 operations were used so we return 3.
It can be shown that we cannot reduce the sum by at least half in less than 3 operations.

Example 2:
Input: nums = [3,8,20]
Output: 3
Explanation: The initial sum of nums is equal to 3 + 8 + 20 = 31.
The following is one of the ways to reduce the sum by at least half:
Pick the number 20 and reduce it to 10.
Pick the number 10 and reduce it to 5.
Pick the number 3 and reduce it to 1.5.
The final array is [1.5, 8, 5] with a total sum of 1.5 + 8 + 5 = 14.5. 
The sum of nums has been reduced by 31 - 14.5 = 16.5, which is at least half of the initial sum, 16.5 >= 31/2 = 15.5.
Overall, 3 operations were used so we return 3.
It can be shown that we cannot reduce the sum by at least half in less than 3 operations.

Constraints:
1 <= nums.length <= 105
1 <= nums[i] <= 107
*/
/*
SOLUTION DESCRIPTION
Create a priority queue so I can always access the maximum value.
Get the total sum by looping through the nums vector and adding value to a running total.
Create a goal of total sum / 2, as described in the problem description.
While the sum is greater than the goal sum:
  Remove the max value from the priority queue.
  Subtract half that value from the total sum.
  Add back in half of the max value.
  Increment the number of operations.
Once the total sum reaches the goal, you can return how many steps it took.
*/
class Solution {
public:
    int halveArray(vector<int>& nums) {
        std::priority_queue<double> numsD;
        double totalSum = 0;
        for(int i = 0; i < nums.size(); i++){
            numsD.push(nums[i]);
            totalSum += nums[i];
        }
        double sumGoal = totalSum / 2;
        int numOps = 0;
        while(totalSum > sumGoal){
            double maxVal = numsD.top();
            totalSum -= maxVal/2;
            numsD.pop();
            numsD.push(maxVal/2);
            numOps++;
        }
        return numOps;
    }
};
