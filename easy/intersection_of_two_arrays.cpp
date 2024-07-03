/*
PROBLEM (easy)
Given two integer arrays nums1 and nums2, return an array of their intersection.
Each element in the result must be unique and you may return the result in any order.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.

Constraints:
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
*/
// Yes I could just use a set, but this was more intereseting imo
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // sort for easy comparison and traversal
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> r = {};
        int i = 0;
        int j = 0;
        while(i < nums1.size() && j < nums2.size()){
            cout << i << j << endl;
            // if its a match, record value and update both indices
            if(nums1[i] == nums2[j]){
                r.push_back(nums1[i]);
                i++;
                j++;
            } else{
                // update the smaller value to move closer to larger value for potential match
                if(nums1[i] < nums2[j]){
                    i++;
                } else{
                    j++;
                }
            }
            // if the end was reached, return
            if(i >= nums1.size()) return r;
            if(j >= nums2.size()) return r;

            // update i, only after it has been incremented at least once
            if(i > 0){
                while(nums1[i] == nums1[i-1]){
                    cout << i;
                    i++;
                    if(i >= nums1.size()) return r;
                }
            }
            // update j, only after it has been incremented at least once
            if(j > 0){
                while(nums2[j] == nums2[j-1]){
                    j++;
                    if(j >= nums2.size()) return r;
                }
            }
        }
        return r;
    }
};
