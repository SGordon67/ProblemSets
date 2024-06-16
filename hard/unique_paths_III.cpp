/*
PROBLEM (hard)
You are given an m x n integer array grid where grid[i][j] could be:
1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.
0 representing empty squares we can walk over.
-1 representing obstacles that we cannot walk over.

Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

Example 1:
Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)

Example 2:
Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)

Example 3:
Input: grid = [[0,1],[2,0]]
Output: 0
Explanation: There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 20
1 <= m * n <= 20
-1 <= grid[i][j] <= 2
There is exactly one starting cell and one ending cell.
*/
// Not an efficient solution, will look into other solutions after this submission
class Solution {
public:
    void findPaths(vector<vector<int>> grid, int sx, int sy, int& numPaths){
        // if -1, you shouldn't be here?
        if(grid[sx][sy] == -1) return;

        // return if you are on the destination
        if(grid[sx][sy] == 2){
            bool fnwt = false; // found non walked tile
            for(int i = 0; i < grid.size(); i++){
                for(int j = 0; j < grid[0].size(); j++){
                    if(grid[i][j] == 0){
                        fnwt = true;
                        break;
                    }
                }
                if(fnwt) break;
            }
            if(!fnwt) numPaths++;
            return;
        }
        // cannot return to current position
        grid[sx][sy] = -1;

        // recurse in all possible directions
        // up
        if(sx > 0){
            if(grid[sx-1][sy] != -1){
                findPaths(grid, sx-1, sy, numPaths);
            }
        }
        // down
        if(sx < grid.size()-1){
            if(grid[sx+1][sy] != -1){
                findPaths(grid, sx+1, sy, numPaths);
            }
        }
        // left
        if(sy > 0){
            if(grid[sx][sy-1] != -1){
                findPaths(grid, sx, sy-1, numPaths);
            }
        }
        // right
        if(sy < grid[0].size()-1){
            if(grid[sx][sy+1] != -1){
                findPaths(grid, sx, sy+1, numPaths);
            }
        }
        return;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        // get the starting position
        int sx = 0;
        int sy = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    sx = i;
                    sy = j;
                }
            }
        }
        int numPaths = 0;
        findPaths(grid, sx, sy, numPaths);
        return numPaths;
    }
};
