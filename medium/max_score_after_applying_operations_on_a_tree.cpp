/*
PROBLEM DESCRIPTION
There is an undirected tree with n nodes labeled from 0 to n - 1, and rooted at node 0. You are given a 2D integer array edges of length n - 1, 
  where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
You are also given a 0-indexed integer array values of length n, where values[i] is the value associated with the ith node.

You start with a score of 0. In one operation, you can:
Pick any node i.
Add values[i] to your score.
Set values[i] to 0.
A tree is healthy if the sum of values on the path from the root to any leaf node is different than zero.

Return the maximum score you can obtain after performing these operations on the tree any number of times so that it remains healthy.

Example 1:
Input: edges = [[0,1],[0,2],[0,3],[2,4],[4,5]], values = [5,2,5,2,1,1]
Output: 11
Explanation: We can choose nodes 1, 2, 3, 4, and 5. The value of the root is non-zero. Hence, the sum of values on the path from the root to any leaf is different than zero. Therefore, the tree is healthy and the score is values[1] + values[2] + values[3] + values[4] + values[5] = 11.
It can be shown that 11 is the maximum score obtainable after any number of operations on the tree.

Example 2:
Input: edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]], values = [20,10,9,7,4,3,5]
Output: 40
Explanation: We can choose nodes 0, 2, 3, and 4.
- The sum of values on the path from 0 to 4 is equal to 10.
- The sum of values on the path from 0 to 3 is equal to 10.
- The sum of values on the path from 0 to 5 is equal to 3.
- The sum of values on the path from 0 to 6 is equal to 5.
Therefore, the tree is healthy and the score is values[0] + values[2] + values[3] + values[4] = 40.
It can be shown that 40 is the maximum score obtainable after any number of operations on the tree.

Constraints:
2 <= n <= 2 * 104
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
values.length == n
1 <= values[i] <= 109
The input is generated such that edges represents a valid tree.
*/
/*
SOLUTION DESCRIPTION
Dynamic programming solution.
Create an adjacency vector out of the edges vector.
Call the helper function dfs on the root node.
  This will travel down the tree (depth first).
  Then construcuct the solution from the root nodes upwards.
For each node, you must essentially chose between destroying the node, or keeping it to keep the tree healthy.
  This depends on the value of the current node, the value of the subtree (chilren sum), and the value of the minimum values in the subtree (min_children_sum).
  if min_children_sum is 0, then we cannot destroy that node.
  if min_children_sum is greater than the current node value, then destroy entire subtree.
  if value of current node is greater than min_children_sum, then you can destroy current node, and calculate the new values for moving up the tree:
    dp[node] = children_sum - min_children_sum + values[node];
The end result is in dp[0], since that is the maximum value allowed at the root node.
*/
class Solution {
public:
    vector<long long> dfs(int node, vector<vector<int>>& adj, vector<long long> &dp, vector<int> &values){
        if(dp[node] != -1) return {0, 0};
        dp[node] = 0;

        long long children_sum = 0;
        long long min_children_sum = 0;

        for(auto it : adj[node]){
            if(dp[it] == -1){
                auto next = dfs(it, adj, dp, values);
                children_sum += next[0];
                min_children_sum += next[1];
            }
        }
        
        long long val = values[node];
        if(min_children_sum == 0){
            dp[node] = 0;
            return {val, val};
        }
        if(min_children_sum >= val){
            dp[node] = children_sum;
        } else if(val > min_children_sum) {
            dp[node] = children_sum - min_children_sum + values[node];
        }
        return {children_sum + val, min(min_children_sum, val)};
    }
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<vector<int>> adj(n+1);
        vector<long long> dp(n+1, -1);

        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(0, adj, dp, values);

        return dp[0];
    }
};
