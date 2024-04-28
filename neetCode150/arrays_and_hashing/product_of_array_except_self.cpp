/*
PROBLEM
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

Constraints:
2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
*/
/*
SOLUTION
I chose to divide the solution into three categories based on the number of zeroes in the array.
If there are no zeroes, then we can just divide the total product by the element at index i to get the result for that index.
If there is one zero, we have zero result for all indices except when the zero is removed, in which case we take the total product without the zero.
If there are more than one zero, then the result is just a list of zeroes.
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer;
        int zeroes = 0;
        int product = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                zeroes++;
            } else{
                product *= nums[i];
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(zeroes >= 2){
                answer.push_back(0);
            } else if(zeroes == 1){
                if(nums[i] == 0){
                    answer.push_back(product);
                } else{
                    answer.push_back(0);
                }
            } else{
                answer.push_back(product / nums[i]);
            }
        }
        return answer;
    }
};
