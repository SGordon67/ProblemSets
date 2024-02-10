/*
PROBLEM DESCRIPTION
Alice has n candies, where the ith candy is of type candyType[i]. Alice noticed that she started to gain weight, so she visited a doctor.
The doctor advised Alice to only eat n / 2 of the candies she has (n is always even). Alice likes her candies very much, and she wants to eat the maximum number of different types of candies while still following the doctor's advice.
Given the integer array candyType of length n, return the maximum number of different types of candies she can eat if she only eats n / 2 of them.

Example 1:
Input: candyType = [1,1,2,2,3,3]
Output: 3
Explanation: Alice can only eat 6 / 2 = 3 candies. Since there are only 3 types, she can eat one of each type.

Example 2:
Input: candyType = [1,1,2,3]
Output: 2
Explanation: Alice can only eat 4 / 2 = 2 candies. Whether she eats types [1,2], [1,3], or [2,3], she still can only eat 2 different types.

Example 3:
Input: candyType = [6,6,6,6]
Output: 1
Explanation: Alice can only eat 4 / 2 = 2 candies. Even though she can eat 2 candies, she only has 1 type.

Constraints:
n == candyType.length
2 <= n <= 104
n is even.
-105 <= candyType[i] <= 105
*/
/*
SOLUTION DESCRIPTION
Commented out solution utilizes maps and is inefficient for that reason.

Start by sorting the candyTypes vector.
Loop through the vector until the number of different candies you see equals size/2.
Return dc after either reaching size/2, or the end of the vector.
*/
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        sort(candyType.begin(),candyType.end());
        int dc = 1;
        for(int i = 1; i < candyType.size(); i++) {
            if(dc == candyType.size() / 2) {
                return dc;
            }
            if(candyType[i] > candyType[i - 1]) {
                dc++;
            }
        }
        return dc;

        // map<int, bool> mm;
        // for(int i = 0; i < candyType.size(); i++){
        //     mm[candyType[i]] = true;
        // }
        // return(min(candyType.size()/2, mm.size()));
    }
};
