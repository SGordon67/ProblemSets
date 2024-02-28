/*
PROBLEM DESCRIPTION
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Example 2:
Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

Constraints:
3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-104 <= target <= 104
*/
/*
SOLUTION DESCRIPTION
Two pointers approach.
First sort the vector.
Main loop is from i = 0 to nums.size()-3, this will be the smalles value in the triplet.
For each value of i, keep two pointers starting at i+1 and nums.size()-1.
  Keep moving them inward. (move the left one to the right if the sum is too small, and vice versa).
  You can skip repeated values of i since you have already tried every combo with that value already.
Keeping track of the closest sum you find, return it at the end.
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int c = nums[0] + nums[1] + nums[nums.size()-1];
        sort(nums.begin(), nums.end());

        int i = 0;
        while(i <= nums.size()-3){
            int j = i+1;
            int k = nums.size()-1;

            while(j < k){
                if(abs(target-(nums[i]+nums[j]+nums[k])) < abs(target-c)){
                    c = (nums[i]+nums[j]+nums[k]);
                }
                if(nums[i]+nums[j]+nums[k] < target){
                    j++;
                } else if(nums[i]+nums[j]+nums[k] > target){
                    k--;
                } else{
                    return target;
                }
            }
            i++;
            while(nums[i] == nums[i-1] && i <= nums.size()-3) i++;
        }
        return c;
    }
};
