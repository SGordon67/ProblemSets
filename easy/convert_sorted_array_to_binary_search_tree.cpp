/*
PROBLEM (easy)
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

Example 1:
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:
Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.

Constraints:
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in a strictly increasing order.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* func(vector<int>& nums, int i, int j){
        // if its not a valid subset of nums
        if (i > j) return NULL;
        
        // find the middle
        int m = (i+j)/2;
        TreeNode* root = new TreeNode(nums[m]);

        // recur left and right sides
        root->left = func(nums,i,m-1);
        root->right = func(nums,m+1,j);

        // return root as result after left and right sides are solved
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        // start with entire vector nums in scope, then narrow down with recursion to left and right sides.
        TreeNode* root = func(nums,0,n-1);
        return root;
    }
};
