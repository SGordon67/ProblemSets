/*
PROBLEM DESCRIPTION
You are given an integer array height of length n. 
There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.

Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
In this case, the max area of water (blue section) the container can contain is 49.

Example 2:
Input: height = [1,1]
Output: 1

Constraints:
n == height.length
2 <= n <= 105
0 <= height[i] <= 104
*/
/*
SOLUTION DESCRIPTION
Return simple case of n == 2.
Implemented a greedy solution.
Keep a left and right pointer, moving the pointer pointing to the smaller height inward toward the middle until the pointers meet.
For each pair, calculate the area of water they would hold.
Keep track of the maximum area you find.
After pointers meet, return the maximum.
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() == 2) return (min(height[0], height[1]));

        int lp = 0;
        int rp = height.size()-1;

        int cArea = min(height[lp], height[rp]) * (rp - lp);
        int mArea = cArea;

        while(lp < rp){
            if(height[lp] < height[rp]){
                lp++;
            } else{
                rp--;
            }
            cArea = min(height[lp], height[rp]) * (rp - lp);
            if(cArea > mArea) mArea = cArea;
        }
        return mArea;
    }
};
