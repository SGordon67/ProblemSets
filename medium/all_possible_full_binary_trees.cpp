/*
PROBLEM (medium)
Given an integer n, return a list of all possible full binary trees with n nodes. 
Each node of each tree in the answer must have Node.val == 0.
Each element of the answer is the root node of one possible tree. 
You may return the final list of trees in any order.
A full binary tree is a binary tree where each node has exactly 0 or 2 children.

Example 1:
Input: n = 7
Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]

Example 2:
Input: n = 3
Output: [[0,0,0]]

Constraints:
1 <= n <= 20
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
    vector<vector<TreeNode*>> dp;

    vector<TreeNode*> solve(int n) {
        // even number of nodes cannot be a full binary tree
        if (n % 2 == 0){
            return {};
        }
        // base case where there is only the root node
        if (n == 1){
            dp[1]={new TreeNode()};
            return dp[1];
        }

        // add the two child nodes to the current node, and recur with those until you run out of nodes to add.
        vector<TreeNode*> ans;
        for (int i = 1; i <n; i += 2) {
            vector<TreeNode*> Left = solve(i);
            vector<TreeNode*> Right = solve(n - 1 - i);
            for (TreeNode* l : Left) {
                for (TreeNode* r : Right) {
                    TreeNode* root = new TreeNode();
                    root->left=l;
                    root->right=r;
                    ans.push_back(root);
                }
            }
        }
        dp[n] = ans;
        return dp[n];
    }

    vector<TreeNode*> allPossibleFBT(int n) {
        dp.assign(n + 1, {}); 
        return solve(n);
    }
};
