/*
PROBLEM DESCRIPTION
You are given a 0-indexed m x n integer matrix grid. The width of a column is the maximum length of its integers.
For example, if grid = [[-10], [3], [12]], the width of the only column is 3 since -10 is of length 3.
Return an integer array ans of size n where ans[i] is the width of the ith column.
The length of an integer x with len digits is equal to len if x is non-negative, and len + 1 otherwise.

Example 1:
Input: grid = [[1],[22],[333]]
Output: [3]
Explanation: In the 0th column, 333 is of length 3.

Example 2:
Input: grid = [[-15,1,3],[15,7,12],[5,6,-2]]
Output: [3,1,2]
Explanation: 
In the 0th column, only -15 is of length 3.
In the 1st column, all integers are of length 1. 
In the 2nd column, both 12 and -2 are of length 2.
 
Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 100 
-109 <= grid[r][c] <= 109
*/
/*
SOLUTION DESCRIPTION
First assign the result to be the length of the first grid elements.
Then loop through each item in grid.
If the length of the item found in grid is longer than the result, update the result.

Could use to_string instead of calculating result, but I believe this is faster.
*/
class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int>  r;
        for(int i = 0; i < grid[0].size(); i++){
            int n = 1;
            int t = grid[0][i];
            if(t < 0) n++;
            t = abs(t);
            while(t > 0){
                if(t >= 10) n++;
                t /= 10;
            }
            r.push_back(n);
        }
        for(int i = 0; i < grid.size(); i ++){
            for(int j = 0; j < grid[0].size(); j++){
                int n = 1;
                int t = grid[i][j];
                if(t < 0) n++;
                t = abs(t);
                while(t > 0){
                    if(t >= 10) n++;
                    t /= 10;
                }
                if(r[j] < n) r[j] = n;
            }
        }
        return r;
    }
};
