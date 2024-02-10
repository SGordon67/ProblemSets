/*
PROBLEM DESCRIPTION
You are given an integer array nums. The unique elements of an array are the elements that appear exactly once in the array.
Return the sum of all the unique elements of nums.

Example 1:
Input: nums = [1,2,3,2]
Output: 4
Explanation: The unique elements are [1,3], and the sum is 4.

Example 2:
Input: nums = [1,1,1,1,1]
Output: 0
Explanation: There are no unique elements, and the sum is 0.

Example 3:
Input: nums = [1,2,3,4,5]
Output: 15
Explanation: The unique elements are [1,2,3,4,5], and the sum is 15.
 
Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 100
*/
/*
SOLUTION DESCRIPTION
Create a map of int to int.
For each value in the given vector, increment the map value of that key by 1.
Loop through the map, if the value is 1, add the key to the running total.
Return the running total.
*/
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        map<int, int> m;
        int total = 0;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]]++;
        }
        for(auto const& x : m){
            if(x.second == 1) total += x.first;
        }
        return total;
    }
};
