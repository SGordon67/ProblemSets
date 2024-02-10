/*
PROBLEM DESCRIPTION
You are given a 0-indexed integer array nums. You have to find the maximum sum of a pair of numbers from nums such that the maximum digit in both numbers are equal.
Return the maximum sum or -1 if no such pair exists.

Example 1:
Input: nums = [51,71,17,24,42]
Output: 88
Explanation: 
For i = 1 and j = 2, nums[i] and nums[j] have equal maximum digits with a pair sum of 71 + 17 = 88. 
For i = 3 and j = 4, nums[i] and nums[j] have equal maximum digits with a pair sum of 24 + 42 = 66.
It can be shown that there are no other pairs with equal maximum digits, so the answer is 88.

Example 2:
Input: nums = [1,2,3,4]
Output: -1
Explanation: No pair exists in nums with equal maximum digits.
 
Constraints:
2 <= nums.length <= 100
1 <= nums[i] <= 104
*/
/*
SOLUTION DESCRIPTION
Keep a record of the largest sum in case there is more than one possibility.
Loop through each pair of values in the vector (i, j):
  Get the largest digit in each value.
  If the largest digit is the same, and the two values added is larger than current largest:
    Record the result.
Return the max value found.
*/
class Solution {
public:
    int maxSum(vector<int>& nums) {
        int m = -1;
        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = i+1; j < nums.size(); j++){
                int n1 = nums[i];
                int n2 = nums[j];
                int md1 = n1 % 10;
                int md2 = n2 % 10;
                while(n1 > 0){
                    int temp = n1 % 10;
                    if(temp > md1) md1 = temp;
                    n1 /= 10;
                }
                while(n2 > 0){
                    int temp = n2 % 10;
                    if(temp > md2) md2 = temp;
                    n2 /= 10;
                }
                if(md1 == md2 && nums[i] + nums[j] > m){
                    m = nums[i] + nums[j];
                }
            }
        }
        return m;
    }
};
