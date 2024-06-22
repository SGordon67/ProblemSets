/*
PROBLEM (medium)
You are given two strings of the same length s and t. 
In one step you can choose any character of t and replace it with another character.
Return the minimum number of steps to make t an anagram of s.
An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.

Example 1:
Input: s = "bab", t = "aba"
Output: 1
Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of s.

Example 2:
Input: s = "leetcode", t = "practice"
Output: 5
Explanation: Replace 'p', 'r', 'a', 'i' and 'c' from t with proper characters to make t anagram of s.

Example 3:
Input: s = "anagram", t = "mangaar"
Output: 0
Explanation: "anagram" and "mangaar" are anagrams. 

Constraints:
1 <= s.length <= 5 * 104
s.length == t.length
s and t consist of lowercase English letters only.
*/
class Solution {
public:
    int minSteps(string s, string t) {
        // keep track of the number of each letter in each string
        // +1 if its in s, -1 if its in t
        // if they have the same number of a letter, then it will be 0
        int alph[26]={0};
        for(int i = 0; i < s.length(); i++){
            alph[s[i] - 'a']++;
        }
        for(int i = 0; i < t.length(); i++){
            alph[t[i] - 'a']--;
        }

        // add up all the mismatched characters and divide by 2
        // /2 one differenc between strings is counted as 2, but can be removed with 1 swap
        int total = 0;
        for(int i = 0; i < 26; i++){
            total += abs(alph[i]);
        }
        return total / 2;

        // OLD SOLUTION, NOT EFFICIENT
        /*
        // sort both strings to easily see what characters they have in common
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        int i = 0;
        int j = 0;
        // go through and remove the characters in common
        while(i < s.length() && j < t.length()){
            // if both characters are the same, remove them from both strings and continue
            if(s[i] == t[j]){
                s.erase(i, 1);
                t.erase(j, 1);
            // increment whichever string has the 'smaller' char so they will get closer to matching'
            // this works because they are sorted
            } else if(s[i] < t[j]){
                i++;
            } else{
                j++;
            }
        }
        // since all the remaining letters are different for each string
        // add together and divide by two since you would only need to add to the string that doesn't have that letter.
        return ((s.length() + t.length()) / 2);
        */
    }
};
