/*
PROBLEM
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. 
Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

Example 1:
Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.

Example 2:
Input: nums = [-1,0]
Output: [-1,0]

Example 3:
Input: nums = [0,1]
Output: [1,0]

Constraints:
2 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each integer in nums will appear twice, only two integers will appear once.
*/
/*
SOLUTION
Initial solution used a map to keep count of each of the number's seen.

More efficient solution uses properties of XOR to solve.
If you xor all the numbers together, the ones with freq of 2 will cancel out, leaving us with just the two values with a freq of 1.
We can extract the first value from this by understanding that there is at least 1 bit difference between the two values.
Create a mask to find the bit that is different between the two values.
We then look through the nums again, taking the unique value that matches the mask, since only one of the two unique values will match it.
Xor the first number with the full xor value to get the second number.
Return the pair.
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int fsXor = 0;
        int mask = 1;
        int first = 0;
        for(auto n : nums) fsXor ^= n;
        while(!(fsXor & mask)) mask <<= 1;
        for(auto n : nums){
            if(n & mask) first ^= n;
        }
        return {first, fsXor ^ first};
        // if(nums.size() == 2) return nums;
        // map<int, int> m = {};
        // for(int i = 0; i < nums.size(); i++){
        //     m[nums[i]]++;
        // }
        // vector<int> r = {};
        // for(auto a : m){
        //     if(a.second == 1) r.push_back(a.first);
        // }
        // return r;
    }
};
