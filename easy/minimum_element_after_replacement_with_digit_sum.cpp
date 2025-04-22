/*
PROBLEM
You are given an integer array nums.
You replace each element in nums with the sum of its digits.
Return the minimum element in nums after all replacements.

Example 1:
Input: nums = [10,12,13,14]
Output: 1
Explanation:
nums becomes [1, 3, 4, 5] after all replacements, with minimum element 1.

Example 2:
Input: nums = [1,2,3,4]
Output: 1
Explanation:
nums becomes [1, 2, 3, 4] after all replacements, with minimum element 1.

Example 3:
Input: nums = [999,19,199]
Output: 10
Explanation:
nums becomes [27, 10, 19] after all replacements, with minimum element 10.

Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 104
*/
/* 
SOLUTION
For each value in the given vector, Sum the digits using mod 10 and divide by 10.
Return the minimum.
*/
class Solution {
public:
    int minElement(vector<int>& nums) {
        int min = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            int sum = 0;
            int num = nums[i];
            while(num > 0){
                sum += num % 10;
                num /= 10;
            }
            if(sum < min) min = sum;
        }
        return min;
    }
};
