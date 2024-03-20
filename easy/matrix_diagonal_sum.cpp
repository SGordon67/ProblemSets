/*
PROBLEM
Given a square matrix mat, return the sum of the matrix diagonals.
Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.

Example 1:
Input: mat = [[1,2,3],
              [4,5,6],
              [7,8,9]]
Output: 25
Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
Notice that element mat[1][1] = 5 is counted only once.

Example 2:
Input: mat = [[1,1,1,1],
              [1,1,1,1],
              [1,1,1,1],
              [1,1,1,1]]
Output: 8

Example 3:
Input: mat = [[5]]
Output: 5

Constraints:
n == mat.length == mat[i].length
1 <= n <= 100
1 <= mat[i][j] <= 100
*/
/*
SOLUTION
Loop through up to halfway through the first axis of the 2d vector.
Solution takes advantage of symmetry so that we don't have to loop through the entire vector.
For each value of i, you can get all four values:
  two from the row i at position i and size-i.
  two from the row size-i at position i and size-i.
If the size is odd, we must add in the center value after the loop.
Return the sum of all found values.
*/
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        for(int i = 0; i < mat.size()/2; i++){
            sum += mat[i][i];
            sum += mat[i][((mat[0].size() - 1) - i)];
            
            sum += mat[((mat.size() - 1) - i)][i];
            sum += mat[((mat.size() - 1) - i)][((mat[0].size() - 1) - i)];
        }
        if(mat.size() % 2) sum += mat[mat.size()/2][mat.size()/2];
        return sum;
    }
};
