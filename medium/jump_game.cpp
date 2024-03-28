/*
PROBLEM
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.

Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

Constraints:
1 <= nums.length <= 104
0 <= nums[i] <= 105
*/
/*
SOLUTION
Commented out solution Looks backward from the end to see what indices can reach that location.
This ends up looking at too many options to be efficient, may be needed in jump game 2?

Actual solution starts from the left and keeps going as long as some value allowed us to reach that far.
Keep track of the maximum steps you are allowed to take from any given index.
Return true if you reach the end, false if you can no longer move forward and you are not yet at the end.
*/
class Solution {
public:
    // bool getFromIndices(queue<int>& foundIndices, vector<int>& nums, int toIndex){
    //     for(int i = 1; i < toIndex; i++){
    //         if(nums[toIndex - i] >= i){
    //             foundIndices.push(toIndex - i);
    //             if((toIndex - i) == 0) return true;
    //         }
    //     }
    //     return false;
    // }
    bool canJump(vector<int>& nums) {
        int numForward = nums[0];
        int i = 0;
        while(numForward > 0 && i < nums.size()-1){
            i++;
            numForward--;
            if(nums[i] >= numForward) numForward = nums[i];
            if(i >= nums.size()-1) return true;
        }
        return (i >= nums.size()-1);
        // queue<int> foundIndices;
        // foundIndices.push(nums.size()-1);
        
        // while(true){
        //     int toIndex = foundIndices.front();
        //     foundIndices.pop();
        //     bool found = getFromIndices(foundIndices, nums, toIndex);
        //     if(found) return true;
        // }
        // return false;
    }
};
