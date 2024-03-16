/*
PROBLEM
A binary tree is uni-valued if every node in the tree has the same value.
Given the root of a binary tree, return true if the given tree is uni-valued, or false otherwise.

Example 1:
Input: root = [1,1,1,1,1,null,1]
Output: true

Example 2:
Input: root = [2,2,2,5,2]
Output: false

Constraints:
The number of nodes in the tree is in the range [1, 100].
0 <= Node.val < 100
*/
/*
SOLUTION
DFS to check all the nodes in the tree.
If we encounter a node with a value not equal to the roots value, return false.
If we get through the entire tree, return true.
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
    bool isUnivalTree(TreeNode* root) {
        int val = root->val;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode *temp = st.top();
            st.pop();
            if(temp->val != val) return false;
            if(temp->left != nullptr) st.push(temp->left);
            if(temp->right != nullptr) st.push(temp->right);
        }

        return true;
    }
};
