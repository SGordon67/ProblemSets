/*
PROBLEM
Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]

Constraints:
1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/
/*
SOLUTION
Create a map between sorted strings, and a vector of strings that are all anagrams of the sorted string.
Go through the vector, adding each string to the map based on the sorted version of that string.
Once each string in the original vector has been added to the map, you can then reconstruct a vector of vectors from the map to return.
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size() <= 0) return {{}};
        unordered_map<string, vector<string>> m;

        for(int i = 0; i < strs.size(); i++){
            string srtdStr = strs[i];
            sort(srtdStr.begin(), srtdStr.end());
            m[srtdStr].push_back(strs[i]);
        }

        vector<vector<string>> r;
        for(auto x: m){
            r.push_back(x.second);
        }
        return r;
    }
};
