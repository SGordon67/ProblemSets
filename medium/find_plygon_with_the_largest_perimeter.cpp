/*
PROBLEM DESCRIPTION
You are given an array of positive integers nums of length n.
A polygon is a closed plane figure that has at least 3 sides. The longest side of a polygon is smaller than the sum of its other sides.
Conversely, if you have k (k >= 3) positive real numbers a1, a2, a3, ..., ak where a1 <= a2 <= a3 <= ... <= ak and a1 + a2 + a3 + ... + ak-1 > ak, then there always exists a polygon with k sides whose lengths are a1, a2, a3, ..., ak.
The perimeter of a polygon is the sum of lengths of its sides.
Return the largest possible perimeter of a polygon whose sides can be formed from nums, or -1 if it is not possible to create a polygon.

Example 1:
Input: nums = [5,5,5]
Output: 15
Explanation: The only possible polygon that can be made from nums has 3 sides: 5, 5, and 5. The perimeter is 5 + 5 + 5 = 15.

Example 2:
Input: nums = [1,12,1,2,5,50,3]
Output: 12
Explanation: The polygon with the largest perimeter which can be made from nums has 5 sides: 1, 1, 2, 3, and 5. The perimeter is 1 + 1 + 2 + 3 + 5 = 12.
We cannot have a polygon with either 12 or 50 as the longest side because it is not possible to include 2 or more smaller sides that have a greater sum than either of them.
It can be shown that the largest possible perimeter is 12.

Example 3:
Input: nums = [5,5,50]
Output: -1
Explanation: There is no possible way to form a polygon from nums, as a polygon has at least 3 sides and 50 > 5 + 5.

Constraints:
3 <= n <= 105
1 <= nums[i] <= 109
*/
/*
SOLUTION DESCRIPTION
I provide two solutions for this problem.
Start with the soted full vector, calulate this permiter even if invalid shape.
Loop through the vector, starting at the end:
  calculate if the shape is invalid, if so then remove the that element from the vector, since it cannot be included and make a valid polygon.
Return the resulting perimeter.
*/
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long peri  = 0;
        for(int i = 0; i < nums.size(); i++){
            peri += nums[i];
        }
        for(int i = nums.size() - 1; i >= 0; i--){
            long long tPeri = peri - nums[i];
            if(tPeri <= nums[i]) peri -= nums[i];
        }
        if(peri) return peri;
        return -1;
    }
};
/*
SOLUTION DESCRIPTION
Sort the vector so you can easily remove the largest when needed.
For each index:
  Find the each valid polygon with side lengths starting with that index.
  Do this by Looping through from i+2 to the end of vector: (i is start, j is end)
    if this set of sides creates a valid polygon, check if it is larger than current largest, and replace if necessary.
Return the perimeter found, will be -1 if none are found.
*/
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long maxPerimeter  = -1;
        if((nums[0] + nums[1]) > nums[2]) maxPerimeter = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size() - 3; i++){
            long long tPeri = 0;
            bool valid = false;
            for(int a = i; a <= i+2; a++){
                if(a == i+2 && tPeri > nums[a]) valid = true;
                tPeri += nums[a];
            }
            for(int j = i+3; j <= nums.size() - 1; j++){
                if(tPeri > nums[j]){
                    valid = true;
                } else valid = false;
                tPeri += nums[j];
                if(valid && tPeri > maxPerimeter) maxPerimeter = tPeri;
            }
        }
        return maxPerimeter;
    }
};
