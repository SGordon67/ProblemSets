/*
PROBLEM (easy)
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]

Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/
/*
SOLUTION
Create a returning vector.
Recursively call the left side, and add result to the returning vector.
Add root nodes value to returning vector.
Recursively call the right side, and add result to the returning vector.
Return result.
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> r {};
        if(root == nullptr) return r;
        if(root->left != nullptr){
            vector<int> leftSide = inorderTraversal(root->left);
            r.insert(r.end(), leftSide.begin(), leftSide.end());
        }
        r.push_back(root->val);
        if(root->right != nullptr){
            vector<int> rightSide = inorderTraversal(root->right);
            r.insert(r.end(), rightSide.begin(), rightSide.end());
        }
        return r;
    }
};
