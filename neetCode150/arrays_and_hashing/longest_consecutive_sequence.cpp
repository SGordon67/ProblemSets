/*
PROBLEM (medium)
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Constraints:
0 <= nums.length <= 105
-109 <= nums[i] <= 109
*/
/*
SOLUTION
Insert all the elements of nums into a set of integers.
for each integer in nums:
  Find the maximum consecutive sequence starting with that integer.
  If that sequence is larger than the largest seen, then replace it with the new one.
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int LCS = 0;
        for(int num : nums){
            if(set.find(num-1) == set.end()){
                int currNum = num;
                int CCS = 1;
                while(set.find(currNum+1) != set.end()){
                    currNum++;
                    CCS++;
                }
                LCS = max(LCS, CCS);
            }
        }
        return LCS;
    }
};
