/*
PROBLEM DESCRIPTION
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string s, int numRows);

Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I

Example 3:
Input: s = "A", numRows = 1
Output: "A"
Constraints:
1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000
*/
/*
SOLUTION DESCRIPTION
Return simple case immediately.

Construct the pattern in the form of a 2d vector as we go through the string.
Loop until we've added the entire string to the pattern.
  If we are at the top row, append the column of the first 4 characters in the string, and remove them from the string s.
  If we are at rows 2 through numRows-1, append the proper amount of spacers, and then the first character from the string, again removing it from s after.
Once we construct the pattern, extract the result by looping through te 2d array, but looping through the columns first, append anything but the spacers.
Return the result.
*/
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        
        // get the number of columns in the zigzag pattern
        int columns = 0;
        int row = numRows;
        // construct the pattern
        vector<vector<char>> pattern;
        vector<char> col;
        while(s.length() > 0){
            if(row == numRows){
                int tRow = numRows;
                while(tRow > 0){
                    if(s.length() > 0){
                        cout << s[0];
                        col.push_back(s[0]);
                        s.erase(0,1);
                    } else{
                        col.push_back(' ');
                    }
                    tRow--;
                }
                pattern.push_back(col);
                col = {};

                row = 2;
                columns++;

            } else{
                int tRow = numRows;
                while(tRow > 0){
                    if(tRow != row){
                        col.push_back(' ');
                    } else{
                        cout << s[0];
                        col.push_back(s[0]);
                        s.erase(0,1);
                    }
                    tRow--;
                }
                pattern.push_back(col);
                col = {};

                columns++;
                row++;
            }
        }

        // extract solution
        string r = "";
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < columns; j++){
                if(pattern[j][i] != ' ') r.push_back(pattern[j][i]);
            }
        }

        return r;

    }
};
