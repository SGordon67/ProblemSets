/*
PROBLEM DESCRIPTION
Given a sorted array of distinct integers and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4

Constraints:
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
*/
/*
SOLUTION DESCRIPTION
Binary Search
O(log n) requirement forces binary search instead of a linear placement.
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int v = (l+r)/2;
        while(l <= r){
            v = (l+r)/2;
            if(nums[v] == target) return v;
            if(nums[v] < target){
                l = v+1;
            } else{
                r = v-1;
            }
        }
        return (nums[v] < target ? v+1 : v);
    }
};
