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
    // function takes in a root node, if the node was a left child, and the sum total
    // does a depth first search on the tree looking for left children
    void subTreeSum(TreeNode* root, bool left, int& total){
        if(root->left == nullptr && root->right == nullptr){ 
            if(left) total += root->val;
            return;
        } else if(root->left == nullptr){
            subTreeSum(root->right, false, total);
        } else if(root->right == nullptr){
            subTreeSum(root->left, true, total);
        } else{
            subTreeSum(root->right, false, total);
            subTreeSum(root->left, true, total);
        }

    }

    int sumOfLeftLeaves(TreeNode* root) {
        int total = 0;
        subTreeSum(root, false, total);
        return total;
    }
};
