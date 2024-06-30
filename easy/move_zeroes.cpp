/*
PROBLEM (easy)
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0]
Output: [0]

Constraints:
1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1

Follow up: Could you minimize the total number of operations done?
only loop through vector once is minimized.
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // i represents the number of non-zero nums we found
        // j is our index walking through the vector looking for nums
        int i = 0;
        int j = 0;

        while(j < nums.size()){
            if(nums[j] == 0){
                j++;
                continue;
            }
            // if you find a non-zero, swap it to the ith index, continue forward
            int temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
            i++;
            j++;
        }
        return;
    }
};
