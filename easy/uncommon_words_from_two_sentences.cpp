/*
PROBLEM (easy)
A sentence is a string of single-space separated words where each word consists only of lowercase letters.
A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.
Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.

Example 1:
Input: s1 = "this apple is sweet", s2 = "this apple is sour"
Output: ["sweet","sour"]

Example 2:
Input: s1 = "apple apple", s2 = "banana"
Output: ["banana"]

Constraints:
1 <= s1.length, s2.length <= 200
s1 and s2 consist of lowercase English letters and spaces.
s1 and s2 do not have leading or trailing spaces.
All the words in s1 and s2 are separated by a single space.
*/
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> m;
        string word = "";
        // loop through first string, gather words and keep track of occurences
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] == ' '){
                m[word]++;
                word = "";
            }else if(i == s1.size()-1){
                word += s1[i];
                m[word]++;
            }else{
                word += s1[i];
            }
        }

        // same thing with second string
        word = "";
        for(int i = 0; i < s2.size(); i++){
            if(s2[i] == ' '){
                m[word]++;
                word = "";
            }else if(i == s2.size()-1){
                word += s2[i];
                m[word]++;
            }else{
                word += s2[i];
            }
        }

        // if the word appears only once throughout both strings, add it to result
        vector<string> words;
        for(auto w : m){
            if(w.second == 1){
                words.push_back(w.first);
            }
        }
        return words;
    }
};
