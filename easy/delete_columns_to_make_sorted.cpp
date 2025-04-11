/*
PROBLEM DESCRIPTION
You are given an array of n strings strs, all of the same length.
The strings can be arranged such that there is one on each line, making a grid.
For example, strs = ["abc", "bce", "cae"] can be arranged as follows:
abc
bce
cae
You want to delete the columns that are not sorted lexicographically. 
In the above example (0-indexed), columns 0 ('a', 'b', 'c') and 2 ('c', 'e', 'e') are sorted, while column 1 ('b', 'c', 'a') is not, so you would delete column 1.

Return the number of columns that you will delete.

Example 1:
Input: strs = ["cba","daf","ghi"]
Output: 1
Explanation: The grid looks as follows:
  cba
  daf
  ghi
Columns 0 and 2 are sorted, but column 1 is not, so you only need to delete 1 column.

Example 2:
Input: strs = ["a","b"]
Output: 0
Explanation: The grid looks as follows:
  a
  b
Column 0 is the only column and is sorted, so you will not delete any columns.

Example 3:
Input: strs = ["zyx","wvu","tsr"]
Output: 3
Explanation: The grid looks as follows:
  zyx
  wvu
  tsr
All 3 columns are not sorted, so you will delete all 3.

Constraints:
n == strs.length
1 <= n <= 100
1 <= strs[i].length <= 1000
strs[i] consists of lowercase English letters.
*/
/*
SOLUTION DESCRIPTION
Initialize counter to hold number of columns we need to drop.
Loop through the first character in each string (this is the first 'column' in our 2d array).
If any character is smaller than the preview string's character at that index, then the column needs to be thrown out, increment the counter.
Do that for each index.
Return the counter once looped through the entire size of the strings.
*/
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int counter = 0;
        for(int i = 0; i < strs[0].size(); i++){
            bool lexi = true;
            for(int j = 1; j < strs.size(); j++){
                if(strs.size() == 1) break;
                if(strs[j][i] < strs[j-1][i]){
                    lexi = false;
                    break;
                }
            }
            if(!lexi) counter++;
        }
        return counter;
    }
};
