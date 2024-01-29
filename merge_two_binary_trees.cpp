/*
PROBLEM DESCRIPTION
You are given two binary trees root1 and root2.
Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. 
The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.
Return the merged tree.
Note: The merging process must start from the root nodes of both trees.

Example 1:
Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
Output: [3,4,5,5,4,null,7]

Example 2:
Input: root1 = [1], root2 = [1,2]
Output: [2,2]

Constraints:
The number of nodes in both trees is in the range [0, 2000].
-104 <= Node.val <= 104
*/
/*
SOLUTION DESCRIPTION
Solution is recursive.
Start with the root node of each tree.
First make sure that nither root node is null, otherwise you just return the non-null root (or null if both roots are null)
Add the values, recurse by doing the left then right side of the trees.
For the left side:
  If both root1.left and root2.left are null then assign new left to be null.
  If just root1.left is null then assign new left to be root2.left.
  If just root2.left is null then assign new left to be root1.left.
  If neither is null then recurse down using root1.left and root2.left as the new roots.
Mirror this solution for the right side of the tree.
Return the resulting node.
*/
/**
 * Definition for a binary tree node->
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
    TreeNode* mergeSubTree(TreeNode* root1, TreeNode* root2){
        if(root1 == nullptr && root2 == nullptr){
            return nullptr;
        } else if(root1 == nullptr){
            return root2;
        } else if(root2 == nullptr){
            return root1;
        }

        TreeNode * r = new TreeNode(root1->val + root2->val);
        if(root1->left == nullptr && root2->left == nullptr){
            r->left = nullptr;
        } else if(root1->left == nullptr){
            r->left = root2->left;
        } else if(root2->left == nullptr){
            r->left = root1->left;
        } else{
            r->left = mergeSubTree(root1->left, root2->left);
        }

        if(root1->right == nullptr && root2->right == nullptr){
            r->right = nullptr;
        } else if(root1->right == nullptr){
            r->right = root2->right;
        } else if(root2->right == nullptr){
            r->right = root1->right;
        } else{
            r->right = mergeSubTree(root1->right, root2->right);
        }

        return r;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* r;
        r = mergeSubTree(root1, root2);
        return r;

    }
};
