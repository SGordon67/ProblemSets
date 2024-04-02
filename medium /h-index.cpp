/*
PROBLEM
Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return the researcher's h-index.
According to the definition of h-index on Wikipedia: 
The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.

Example 1:
Input: citations = [3,0,6,1,5]
Output: 3
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.

Example 2:
Input: citations = [1,3,1]
Output: 1

Constraints:
n == citations.length
1 <= n <= 5000
0 <= citations[i] <= 1000
*/
/*
SOLUTION
Initial solution (commented out) utilized the first half of counting sort to generate an array that can tell if the number of papers with n citations was at least n.
More efficient solution simply sorts the array normally, then moves from right to left counting if that number of citations fits the criteria to continue or return.
*/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int ans = 0;
        for(int i = citations.size()-1; i >= 0; i--){
            if(citations[i] >= (citations.size() - i)){
                ans++;
            }else break;
        }
        return ans;

        // vector<int> counter;
        // for (std::size_t i = 0; i <= 1000; ++i){
        //     counter.push_back(0);
        // }
        // for(int i = 0; i < citations.size(); i++){
        //     counter[citations[i]]++;
        // }
        // int tally = 0;
        // for(int i = counter.size()-1; i >= 0; i--){
        //     tally += counter[i];
        //     counter[i] = tally;
        //     if(counter[i] >= i) return i;
        // }
        // return 0;
    }
};
