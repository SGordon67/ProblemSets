/*
PROBLEM (medium)
Given the root of a binary tree, determine if it is a valid binary search tree (BST).
A valid BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:
Input: root = [2,1,3]
Output: true

Example 2:
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

Constraints:
The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
/*
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
    bool helperBST(TreeNode* root, int lLimit, int rLimit, bool lReached, bool rReached){
        // base case is leaf nodes, which you just need to check limits sperately with values
        if(root->left == nullptr && root->right == nullptr){
            if(lReached && root->val == INT_MIN) return false;
            if(rReached && root->val == INT_MAX) return false;
            if(root->val <= lLimit && !((root->val == INT_MIN) || (root->val == INT_MAX))) return false;
            if(root->val >= rLimit && !((root->val == INT_MIN) || (root->val == INT_MAX))) return false;

            return true;
        }

        // helper variables for left and right sides
        bool lValid = true;
        bool rValid = true;
        TreeNode* lTree = root->left;
        TreeNode* rTree = root->right;

        // recurse down the left and right sides of the tree
        if(lTree != nullptr){
            if(root->val == INT_MIN) return false;
            lValid = helperBST(lTree, lLimit, root->val, false, root->val == INT_MAX);
            if(!lValid) return false;

            // if left side is greater than or equal to root, it is invalid
            if(lTree->val >= root->val) return false;
            // if you are past the limit, invalid
            if(lTree->val < lLimit) return false;
            // if you have the minimum value, and it has been used already, invalid
            if(lReached && lTree->val == lLimit) return false;
        }
        if(rTree != nullptr){
            if(root->val == INT_MAX) return false;
            rValid = helperBST(rTree, root->val, rLimit, root->val == INT_MIN, false);
            if(!rValid) return false;

            // if right side is less than or equal to root, it is invalid
            if(rTree->val <= root->val) return false;
            // if values work, check if it works with greater context of tree and limits
            if(rTree->val > rLimit) return false;
            // if you have the maximum value, and it has already been used, invalid
            if(rReached && rTree->val == rLimit) return false;
        }

        // if you get through all checks, return true
        return true;
    }
    bool isValidBST(TreeNode* root) {
        // must pass the current min/max allowed for current node, and wether or not we've reached the max/min allowed
        return helperBST(root, INT_MIN, INT_MAX, false, false);
    }
};
