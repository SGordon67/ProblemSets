/*
PROBLEM
Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:
Input: numRows = 1
Output: [[1]]

Constraints:
1 <= numRows <= 30
*/
/*
SOLUTION
Utilize dynamic programming to generate the new rows based on the previous rows until the desired number of rows is generated.
/*
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int rowsAdded = 0;
        vector<vector<int>> pt;
        pt.push_back({1});
        rowsAdded++;
        if(numRows == rowsAdded) return pt;
        pt.push_back({1,1});
        rowsAdded++;
        if(numRows == rowsAdded) return pt;

        while(numRows > rowsAdded){
            vector<int> newRow;
            newRow.push_back(1);
            for(int i = 1; i < pt[pt.size()-1].size(); i++){
                newRow.push_back(pt[pt.size()-1][i-1] + pt[pt.size()-1][i]);
            }
            newRow.push_back(1);
            pt.push_back(newRow);
            rowsAdded++;
        }
        return pt;
    }
};
