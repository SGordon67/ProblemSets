/*
PROBLEM DESCRIPTION
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

Constraints:
3 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/
/*
SOLUTION DESCRIPTION
For each index i from 0 to nums.size - 3 (because you need to leave room for two more indices).
  Have two pointers j and k that point to i+1 and nums.size()-1 respectively.
  While j < k:
    If the three values at i, j, and k add up to be smaller than 0, move j to the right.
    If they add to be larger than 0, move k to the left.
    If they exactly add to 0:
      Add the vector {nums[i], nums[j], nums[k]} to the map r. (to keep these values unique)
      Move j to the right and k to the left.
  If the next value of i is the same as the previous, skip it to avoid repeats.
Return all the keys in the map as a vector.
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<vector<int>, int> r;
        sort(nums.begin(), nums.end());

        int i = 0;
        while(nums[i] <= 0 && i <= nums.size()-3){
            int j = i+1;
            int k = nums.size()-1;
            while(j < k){
                if(nums[i] + nums[j] + nums[k] < 0){
                    j++;
                } else if(nums[i] + nums[j] + nums[k] > 0){
                    k--;
                } else{
                    r[{nums[i], nums[j], nums[k]}]++;
                    j++;
                    k--;
                }
            }
            i++;
            while(nums[i] == nums[i-1] && i <= nums.size()-3) i++;
        }
        vector<vector<int>> z = {};
        for(auto a : r){
            z.push_back(a.first);
        }
        return z;
    }
};
