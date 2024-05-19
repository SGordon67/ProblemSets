/*
PROBLEM (easy)
You are given an array of integers nums. Return the length of the longest 
subarray of nums which is either strictly increasing or strictly decreasing.

Example 1:
Input: nums = [1,4,3,3,2]
Output: 2
Explanation:
The strictly increasing subarrays of nums are [1], [2], [3], [3], [4], and [1,4].
The strictly decreasing subarrays of nums are [1], [2], [3], [3], [4], [3,2], and [4,3].
Hence, we return 2.

Example 2:
Input: nums = [3,3,3,3]
Output: 1
Explanation:
The strictly increasing subarrays of nums are [3], [3], [3], and [3].
The strictly decreasing subarrays of nums are [3], [3], [3], and [3].
Hence, we return 1.

Example 3:
Input: nums = [3,2,1]
Output: 3
Explanation:
The strictly increasing subarrays of nums are [3], [2], and [1].
The strictly decreasing subarrays of nums are [3], [2], [1], [3,2], [2,1], and [3,2,1].
Hence, we return 3.

Constraints:
1 <= nums.length <= 50
1 <= nums[i] <= 50
*/
/*
SOLUTION
Go through the array linearly, keeping track of the current increasying and decreasing subarrays.
Keep note of the longest one of each, and return the longest of the two.
*/
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int mx = 1;
        int omx= 1;
        int cur = 1;
        int ocur = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            cur = (nums[i]>nums[i-1])? cur +1: 1;
            mx = max(mx, cur);

            ocur = (nums[i]<nums[i-1])? ocur + 1: 1;
            omx = max(omx, ocur);
        }
        return max(mx,  omx);
    }
};
