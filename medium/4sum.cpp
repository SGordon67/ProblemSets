/*
PROBLEM
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]

Constraints:
1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/
/*
SOLUTION
Sort vector.
Two for loops going from first two indices to end of sorted nums vector (-3 and -2 respectively).
  These are the first two values to check for a quad.
Use the two pointer method from here to find two values that match the first two to get the target.
  Add vector of quad numbers to solution if total matches.
  Move the left one to the right if the total is too small.
  Move the right one to the left if the total is too large.
Extract the solution from the map.
Return.
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) return {};
        map<vector<int>, int> m;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size()-3; i++){
            for(int j = i+1; j < nums.size()-2; j++){
                long long t2 = target - (long long)(nums[i] + nums[j]);
                int k = j+1;
                int l = nums.size()-1;
                while(k < l){
                    if(nums[k] + nums[l] == t2){
                        m[{nums[i], nums[j], nums[k], nums[l]}]++;
                        k++;
                        l--;
                    } else if(nums[k] + nums[l] < t2){
                        k++;
                    } else{
                        l--;
                    }
                }
            }
        }
        
        vector<vector<int>> r;
        for(auto x : m){
            r.push_back(x.first);
        }
        return r;
    }
};
