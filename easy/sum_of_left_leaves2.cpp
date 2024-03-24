/*
PROBLEM
Given the root of a binary tree, return the sum of all left leaves.
A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.

Example 2:
Input: root = [1]
Output: 0

Constraints:
The number of nodes in the tree is in the range [1, 1000].
-1000 <= Node.val <= 1000
*/
/*
SOLUTION
Keep a running total while looping through the tree looking for leaf nodes.
When you run into a leaf node, if it is a left child then add to sum.
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
    void helper(TreeNode* root, bool left, int& sum){
        if(root->left == nullptr && root->right == nullptr){
            if(left) sum += root->val;
        }
        if(root->left != nullptr) helper(root->left, true, sum);
        if(root->right != nullptr) helper(root->right, false, sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if(root == nullptr) return 0;
        helper(root, false, sum);
        return sum;
    }
};
