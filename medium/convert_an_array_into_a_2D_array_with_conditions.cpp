/*
PROBLEM (medium)
You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:

The 2D array should contain only the elements of the array nums.
Each row in the 2D array contains distinct integers.
The number of rows in the 2D array should be minimal.
Return the resulting array. If there are multiple answers, return any of them.

Note that the 2D array can have a different number of elements on each row.

Example 1:
Input: nums = [1,3,4,1,2,3,1]
Output: [[1,3,4,2],[1,3],[1]]
Explanation: We can create a 2D array that contains the following rows:
- 1,3,4,2
- 1,3
- 1
All elements of nums were used, and each row of the 2D array contains distinct integers, so it is a valid answer.
It can be shown that we cannot have less than 3 rows in a valid array.

Example 2:
Input: nums = [1,2,3,4]
Output: [[4,3,2,1]]
Explanation: All elements of the array are distinct, so we can keep all of them in the first row of the 2D array.

Constraints:
1 <= nums.length <= 200
1 <= nums[i] <= nums.length
*/
/*
SOLUTION
Sort the input.
Go through the sorted input linearly.
Place each repeating value in the next subarray of the result.
Restart at 0 when you find a non-repeated value.
The only complexity is deciding when to add a new array, or add to an existing one.
This is done by keeping track of the current length of repeated values,
  and comparing this with longest string of duplicate values you have i.e. the mode.
*/
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> r = {};

        int modeSize = 1;
        int currSize = 1;
        
        r.push_back({nums[0]});

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]){
                currSize++;
            } else{
                currSize = 1;
            }

            if(currSize > modeSize){
                r.push_back({nums[i]});
            } else{
                r[currSize-1].push_back(nums[i]);
            }
            modeSize = max(currSize, modeSize);
        }

        return r;
    }
};
