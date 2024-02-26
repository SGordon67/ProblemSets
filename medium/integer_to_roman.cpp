/*
PROBLEM DESCRIPTION
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. 
Because the one is before the five we subtract it making four. 
The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.

Example 1:
Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.

Example 2:
Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.

Example 3:
Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

Constraints:
1 <= num <= 3999
*/
/*
SOLUTION DESCRIPTION
Solution that is commented out does not hard code the values, and instead generates them as it goes.
This costs time but is more scalable, easier to include larger roman numerals.

The more efficient soution, utilizes a vector of pairs that hard codes the value for every possible roman numeral up to 1000.
The loop takes the largest value smaller than num, subtracts it from num and adds its roman representation to the returning string.
*/
class Solution {
public:
    string intToRoman(int num) {
        string r = "";
        vector<pair<int, string>> rv = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

        for(int i = 0; i < rv.size(); i++){
            while(num >= rv[i].first){
                r += rv[i].second;
                num -= rv[i].first;
            }
        }
        return r;

        // Commented out solution mentioned above.
        // int rv[7] = {1,5,10,50,100,500,1000};
        // char rvc[7] = {'I','V','X','L','C','D','M'};
        // string r = "";
        // int offset = 2;
        // while(num > 0){
        //     for(int i = 6; i >= 0; i--){
        //         if(num >= rv[i]){
        //             num -= rv[i];
        //             r += rvc[i];
        //             break;
        //         } else if(num >= rv[i] - rv[i-offset]){
        //             num -= (rv[i] - rv[i-offset]);
        //             r += rvc[i-offset];
        //             r += rvc[i];
        //             break;
        //         } else{
        //             offset--;
        //             if(offset <= 0 && i != 1) offset = 2;
        //         }
        //     }
        // }
        // return r;
    }
};
