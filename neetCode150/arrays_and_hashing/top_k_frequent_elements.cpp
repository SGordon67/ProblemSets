/*
PROBLEM
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/
/*
SOLUTION
Create a map between values and frequencies.
Create a vector of pairs out of this map, and sort based on the frequencies.
Grab the values associated with the k largest frequencies.
Return the result as a vector.
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        vector<pair<int, int>> sorted(mp.begin(), mp.end());
        sort(sorted.begin(), sorted.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });

        vector<int> r;
        for(int i = 0; i < k && i < sorted.size(); i++){
            r.push_back(sorted[i].first);
        }
        return r;
    }
};
