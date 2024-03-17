/*
PROBLEM
There is a survey that consists of n questions where each question's answer is either 0 (no) or 1 (yes).
The survey was given to m students numbered from 0 to m - 1 and m mentors numbered from 0 to m - 1. 
The answers of the students are represented by a 2D integer array students where students[i] is an integer array that contains the answers of the ith student (0-indexed). 
The answers of the mentors are represented by a 2D integer array mentors where mentors[j] is an integer array that contains the answers of the jth mentor (0-indexed).
Each student will be assigned to one mentor, and each mentor will have one student assigned to them. 
The compatibility score of a student-mentor pair is the number of answers that are the same for both the student and the mentor.
For example, if the student's answers were [1, 0, 1] and the mentor's answers were [0, 0, 1], then their compatibility score is 2 because only the second and the third answers are the same.
You are tasked with finding the optimal student-mentor pairings to maximize the sum of the compatibility scores.
Given students and mentors, return the maximum compatibility score sum that can be achieved.

Example 1:
Input: students = [[1,1,0],[1,0,1],[0,0,1]], mentors = [[1,0,0],[0,0,1],[1,1,0]]
Output: 8
Explanation: We assign students to mentors in the following way:
- student 0 to mentor 2 with a compatibility score of 3.
- student 1 to mentor 0 with a compatibility score of 2.
- student 2 to mentor 1 with a compatibility score of 3.
The compatibility score sum is 3 + 2 + 3 = 8.

Example 2:
Input: students = [[0,0],[0,0],[0,0]], mentors = [[1,1],[1,1],[1,1]]
Output: 0
Explanation: The compatibility score of any student-mentor pair is 0.

Constraints:
m == students.length == mentors.length
n == students[i].length == mentors[j].length
1 <= m, n <= 8
students[i][k] is either 0 or 1.
mentors[j][k] is either 0 or 1.
*/
/*
SOLUTION
The high level explanation of the solution.
For student 1, take each scenario of assigning each mentor to this student.
  For each of these scenarios, continue down the list of students assigning mentors using the same logic.
    Once you reach the end, calculate the score that that setup acheives, and update the max.
Return the max value we found.
*/
class Solution {
public:
    int ans = 0;
    int score(vector<int>&v1, vector<int>&v2, int m){
        int c = 0;
        for(int i = 0; i < m; i++){
            c += (v1[i] == v2[i]);
        }
        return c;
    }
    void dp(int idx, vector<int>&arr, vector<vector<int>>& stdnts, vector<vector<int>> &mntrs, int n, int m){
        if(idx == arr.size()){
            int sum = 0;
            for(int i=0; i<n; i++){
                sum += score(stdnts[i], mntrs[arr[i]], m);
            }
            ans = max(ans, sum);
            return;
        }
        for(int i=idx; i<arr.size(); i++){
            swap(arr[idx], arr[i]);
            dp(idx+1, arr, stdnts, mntrs, n, m);
            swap(arr[idx], arr[i]);
        }
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n = students.size();
        int m = students[0].size();
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            arr[i] = i;
        }
        dp(0, arr, students, mentors, n, m);
        return ans;
    }
};
