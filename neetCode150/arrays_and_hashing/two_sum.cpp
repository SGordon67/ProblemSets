/*
PROBLEM (easy)
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]

Constraints:
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 
Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
(already within this requirement)
*/
/*
SOLUTION
Create a map that stores the values seen as you loop through the vector.
Check to see if the compliment exists in the map already for each value you find.
Once you find the value that has a compliment, return those two values.
Since the solution is guarunteed to be unique, that is all that is needed.
Decided to return 0,0 in case of some error in question formatting.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            if(m.find(target - nums[i]) == m.end()){
                m[nums[i]] = i;
            } else{
                return {(m.find(target - nums[i]))->second, i};
            }
        }
        return {0, 0};
    }
};