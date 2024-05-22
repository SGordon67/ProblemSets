/*
PROBLEM (hard)
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Constraints:
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/
/*
SOLUTION
My solution is essentially an implementation of merge sort.
I merge the two arrays, one value at a time, only taking the smallest of the two arrays.
Once my merged array reaches at least the size of half of the combined sizes, I can stop.
If total size is odd, I simply return the last value I merged on.
If the total size is even, I must average the last two values I merged on.
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalSize = nums1.size() + nums2.size();
        vector<int> a = {};
        while(a.size() <= (totalSize / 2)){
            if(nums1.size() > 0 && nums2.size() > 0){
                if(nums1[0] <= nums2[0]){
                    a.push_back(nums1[0]);
                    nums1.erase(nums1.begin());
                } else{
                    a.push_back(nums2[0]);
                    nums2.erase(nums2.begin());
                }
            } else if(nums1.size() > 0){
                a.push_back(nums1[0]);
                nums1.erase(nums1.begin());
            } else{
                a.push_back(nums2[0]);
                nums2.erase(nums2.begin());
            }
        }
        if((totalSize % 2) == 0) {
            return ((double)((a[a.size() - 1]) + (a[a.size() - 2])) / 2);
        }
        return a[a.size() - 1];
    }
};
