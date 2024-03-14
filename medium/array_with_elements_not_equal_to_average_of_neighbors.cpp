/*
PROBLEM
You are given a 0-indexed array nums of distinct integers. 
You want to rearrange the elements in the array such that every element in the rearranged array is not equal to the average of its neighbors.
More formally, the rearranged array should have the property such that for every i in the range 1 <= i < nums.length - 1, (nums[i-1] + nums[i+1]) / 2 is not equal to nums[i].
Return any rearrangement of nums that meets the requirements.

Example 1:
Input: nums = [1,2,3,4,5]
Output: [1,2,4,5,3]
Explanation:
When i=1, nums[i] = 2, and the average of its neighbors is (1+4) / 2 = 2.5.
When i=2, nums[i] = 4, and the average of its neighbors is (2+5) / 2 = 3.5.
When i=3, nums[i] = 5, and the average of its neighbors is (4+3) / 2 = 3.5.

Example 2:
Input: nums = [6,2,0,9,7]
Output: [9,7,6,2,0]
Explanation:
When i=1, nums[i] = 7, and the average of its neighbors is (9+6) / 2 = 7.5.
When i=2, nums[i] = 6, and the average of its neighbors is (7+2) / 2 = 4.5.
When i=3, nums[i] = 2, and the average of its neighbors is (6+0) / 2 = 3.

Constraints:
3 <= nums.length <= 105
0 <= nums[i] <= 105
*/
/*
SOLUTION
Sort the vector.
Go through the vector linearly two at a time, ensureing that the smallest element is in the middle of each set of 3 you encounter.
  That way the average cannot be in the middle.
Check corner case of last three elements needing to swap the largest into the middle to ensure it's not the average.
*/
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 1; i <= nums.size()-2; i+=2){
            int t = nums[i];
            nums[i] = nums[i-1];
            nums[i-1] = t;
        }
        if(nums[n-1-1] == ((nums[n-1-2] + nums[n-1])/2)){
            int t = nums[nums.size()-1];
            nums[nums.size()-1] = nums[nums.size()-2];
            nums[nums.size()-2] = t;
        }
        return nums;
    }
};
