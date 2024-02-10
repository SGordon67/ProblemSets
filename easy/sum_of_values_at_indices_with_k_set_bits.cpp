/*
PROBLEM DESCRIPTION
You are given a 0-indexed integer array nums and an integer k.
Return an integer that denotes the sum of elements in nums whose corresponding indices have exactly k set bits in their binary representation.
The set bits in an integer are the 1's present when it is written in binary.
For example, the binary representation of 21 is 10101, which has 3 set bits.

Example 1:
Input: nums = [5,10,1,5,2], k = 1
Output: 13
Explanation: The binary representation of the indices are: 
0 = 0002
1 = 0012
2 = 0102
3 = 0112
4 = 1002 
Indices 1, 2, and 4 have k = 1 set bits in their binary representation.
Hence, the answer is nums[1] + nums[2] + nums[4] = 13.

Example 2:
Input: nums = [4,3,2,1], k = 2
Output: 1
Explanation: The binary representation of the indices are:
0 = 002
1 = 012
2 = 102
3 = 112
Only index 3 has k = 2 set bits in its binary representation.
Hence, the answer is nums[3] = 1.
 
Constraints:
1 <= nums.length <= 1000
1 <= nums[i] <= 105
0 <= k <= 10
*/

/*
SOLUTION EXPLINATION
create variable total to hold returning value.
loop through each index.
Determine how many bits are set for each given index.
Do this by taking the remainder mod 2, then dividing by 2 until value < 1.
If the remainder is 1, then that bit is set.
If the number of bits set is equal to k, then add the value at that index to the total.
*/
class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int total = 0;
        for(int i = 0; i < nums.size(); i++){
            int setBits = 0;
            int val = i;
            do{
                int pv = val % 2;
                val = val / 2;
                if(pv == 1) setBits++;
            }
            while (val >= 1);
            if(setBits == k) total += nums[i];
        }
        return total;
    }
};
