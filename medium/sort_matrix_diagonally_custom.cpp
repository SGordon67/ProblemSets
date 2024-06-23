/*
PROBLEM (medium) (custom)
I misnderstood a leetcode problem, but I think the problem I solved is cooler than the actual one, so I still want to document it.
The problem as I understood it was to sort the 2d matrix starting in the top right and moving down/left to the bottom left.

Given a matrix of size m x n of integers, sort the matrix along the diagonal lines starting in the top right and moving left/down.

example:
3 3 1 1        2 1 1 1
2 2 1 2  --->  2 2 1 1
1 1 1 2        3 3 2 1

constriaints still make sense in this context:
m == mat.length
n == mat[i].length
1 <= m, n <= 100
1 <= mat[i][j] <= 100
*/
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        // extract the values into a 1d vector and sort
        vector<int> nums = {};
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                nums.push_back(mat[i][j]);
            }
        }
        sort(nums.begin(), nums.end());

        // go through the 2d vector in diagonal order, and insrt from the sorted list of values
        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), 0));
        int i = mat[0].size() - 1;
        int j = 0;
        bool hitCorner = false;
        for(int a = 0; a < nums.size(); a++){
            //cout << nums[a] << ", " << i << ", " << j << endl;
            // assign new value, return if its the last value
            ans[j][i] = nums[a];
            if(i == 0 && j == mat.size() - 1) return ans;

            // update indices based on if you hit the corner or not yet
            if(hitCorner){
                if(i == mat[0].size() - 1 || j == mat.size() - 1){
                    j -= (i-1);
                    i = 0;
                } else{
                    i++;
                    j++;
                }
            } else{
                if(i == mat[0].size() - 1 || j == mat.size() - 1){
                    i -= (j+1);
                    j = 0;
                    if(i == 0) hitCorner = true;
                } else{
                    i++;
                    j++;
                }
            }
        }
        return ans;
    }
};
