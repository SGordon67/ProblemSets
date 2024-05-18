/*
PROBLEM (easy)
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 2
Example 2:

Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
 

Constraints:

The number of nodes in the tree is in the range [0, 105].
-1000 <= Node.val <= 1000
*/
/*
SOLUTION
Do a breadth first search on the tree, keeping track of how deep you have gone.
When you reach a leaf node, return the current depth since that is the most shallow one you will find.
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
    int minDepth(TreeNode* root) {
        int depth = 0;
        if(root == nullptr) return depth;

        queue<TreeNode*> q;
        q.push(root);
        depth++;

        while(!q.empty()){
            int cLength = q.size();
            while(cLength > 0){
                TreeNode* cNode = q.front();
                q.pop();
                if(cNode->left == nullptr && cNode->right == nullptr) return depth;
                if(cNode->left != nullptr) q.push(cNode->left);
                if(cNode->right != nullptr) q.push(cNode->right);
                cLength--;
            }
            depth++;
        }
        return 0;
    }
};
