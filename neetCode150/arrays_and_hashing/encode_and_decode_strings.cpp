/*
PROBLEM
Design an algorithm to encode a list of strings to a single string. The encoded string is then decoded back to the original list of strings.

Please implement encode and decode

Example 1:
Input: ["neet","code","love","you"]
Output:["neet","code","love","you"]

Example 2:
Input: ["we","say",":","yes"]
Output: ["we","say",":","yes"]

Constraints:
0 <= strs.length < 100
0 <= strs[i].length < 200
strs[i] contains only UTF-8 characters.
*/
/*
SOLUTION
Encode each word in the vector to be a number representing the length of the word, and the word itself, separated by a '#'.
Decode by reading the number representing the length of the word, then reading in the word.
  Repeat till the string is empty, dumping the resulting word into a results vector as you go.
*/
class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(int i = 0; i < strs.size(); i++){
            string str = strs[i];
            res += to_string(str.size()) + "#" + str;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;

        int i = 0;
        while(i < s.size()){
            int j = i;
            while(s[j] != '#')j++;
            int wordSize = stoi(s.substr(i,j-i));
            res.push_back(s.substr(j+1, wordSize));
            i = j + 1 + wordSize;
        }
        return res;
    }
};
