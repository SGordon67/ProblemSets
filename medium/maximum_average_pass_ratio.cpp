/*
PROBLEM
There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where classes[i] = [passi, totali]. 
You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.

You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. 
You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.

The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. 
The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.

Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted.

Example 1:
Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
Output: 0.78333
Explanation: You can assign the two extra students to the first class. The average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.

Example 2:
Input: classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
Output: 0.53485

Constraints:
1 <= classes.length <= 105
classes[i].length == 2
1 <= passi <= totali <= 105
1 <= extraStudents <= 105
*/
/*
SOLUTION
Construct a max heap of values that represent the possible change in pass ratio for a given class if that class was given one extraStudent.
While there are still extra students to assign:
  Assign an extra student to the class with the most to gain from an extra student.
    Heap automatically adjusts for us.
  Update the classes vector with new students as you add them.
Once there are no more extra students left, calculate the average from the classes vector.
*/
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> minH;
        for(int i = 0; i < classes.size(); i++){
            double ratDiff = ((double)(classes[i][0]+1) / (double)(classes[i][1]+1)) - ((double)(classes[i][0]) / (double)(classes[i][1]));
            minH.push(make_pair(ratDiff, i));
        }

        while(extraStudents > 0){
            pair<double, int> wClass = minH.top();
            minH.pop();
            classes[wClass.second][0]++;
            classes[wClass.second][1]++;
            wClass.first = ((double)(classes[wClass.second][0]+1) / (double)(classes[wClass.second][1]+1)) - ((double)(classes[wClass.second][0]) / (double)(classes[wClass.second][1]));
            minH.push(wClass);
            extraStudents--;
        }

        double maxAvg = 0;
        for(int i = 0; i < classes.size(); i++){
            cout << (classes[i][0]) << " " << (classes[i][1]) << endl;
            maxAvg += (double)(classes[i][0]) / (double)(classes[i][1]);
        }
        maxAvg /= classes.size();
        return maxAvg;
    }
};
