/*
PROBLEM (medium)
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
/*
SOLUTION
Created a second solution because I revisited this problem later and didn't realize I had already solved it before a slightly different way.
Create a map between values and frequencies.
Insert the pairs of value/frequency into a max heap.
Pop the top k values off the max heap into a vector and return.
*/
typedef pair<int, int> pd;

class Solution2 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // get the frequency of each value
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]]++;
        }

        // insert into max heap
        priority_queue<pd, vector<pd>, 
            decltype([](const pd& pairOne, const pd& pairTwo) -> bool {
                return pairOne.second < pairTwo.second;
            })> pq;
        for( auto a : m ){
            pq.push(make_pair(a.first, a.second));
        }

        // extract most frequent elements
        vector<int> r;
        for(int i = 0; i < k; i++){
            r.push_back(pq.top().first);
            pq.pop();
        }

        return r;
    }
};
