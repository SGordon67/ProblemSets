/*
PROBLEM
Alice and Bob are traveling to Rome for separate business meetings.
You are given 4 strings arriveAlice, leaveAlice, arriveBob, and leaveBob. 
Alice will be in the city from the dates arriveAlice to leaveAlice (inclusive), while Bob will be in the city from the dates arriveBob to leaveBob (inclusive). 
Each will be a 5-character string in the format "MM-DD", corresponding to the month and day of the date.

Return the total number of days that Alice and Bob are in Rome together.
You can assume that all dates occur in the same calendar year, which is not a leap year. 
Note that the number of days per month can be represented as: [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31].

Example 1:
Input: arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", leaveBob = "08-19"
Output: 3
Explanation: Alice will be in Rome from August 15 to August 18. Bob will be in Rome from August 16 to August 19. They are both in Rome together on August 16th, 17th, and 18th, so the answer is 3.

Example 2:
Input: arriveAlice = "10-01", leaveAlice = "10-31", arriveBob = "11-01", leaveBob = "12-31"
Output: 0
Explanation: There is no day when Alice and Bob are in Rome together, so we return 0.

Constraints:
All dates are provided in the format "MM-DD".
Alice and Bob's arrival dates are earlier than or equal to their leaving dates.
The given dates are valid dates of a non-leap year.
*/
/*
SOLUTION
Take input and sanitize.
Calculate the first and last arrival/departure from given info.
Then add up the days inbetwewen the last arrival and the first departure.
Take care for cases where there's no overlap, or complete overlap even if arrival/departure happen in the same month.
*/
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aliceArriveMonth = stoi(arriveAlice.substr(0, 2)); // Alice arrival month
        int aliceArriveDay = stoi(arriveAlice.substr(3, 2)); // Alice arrival day
        int aliceLeaveMonth = stoi(leaveAlice.substr(0, 2)); // Alice leave month
        int aliceLeaveDay = stoi(leaveAlice.substr(3, 2)); // Alice leave day

        int bobArriveMonth = stoi(arriveBob.substr(0, 2)); // Bob arrival month
        int bobArriveDay = stoi(arriveBob.substr(3, 2)); // Bob arrival day
        int bobLeaveMonth = stoi(leaveBob.substr(0, 2)); // Bob leave month
        int bobLeaveDay = stoi(leaveBob.substr(3, 2)); // Bob leave day

        int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if(aliceLeaveMonth < bobArriveMonth || aliceArriveMonth > bobLeaveMonth) return 0; // never meet

        int lastArriveMonth = max(aliceArriveMonth, bobArriveMonth);
        int lastLeaveMonth = max(aliceLeaveMonth, bobLeaveMonth);
        int lastLeaveDay = 0;
        int lastArriveDay = 0;
        int firstArriveMonth = min(aliceArriveMonth, bobArriveMonth);
        int firstLeaveMonth = min(aliceLeaveMonth, bobLeaveMonth);
        int firstLeaveDay = 0;
        int firstArriveDay = 0;

        // determining arrival order
        if(lastArriveMonth == firstArriveMonth){
            lastArriveDay = max(aliceArriveDay, bobArriveDay);
            firstArriveDay = min(aliceArriveDay, bobArriveDay);
        } else if(lastArriveMonth == aliceArriveMonth){
            lastArriveDay = aliceArriveDay;
            firstArriveDay = bobArriveDay;
        } else{
            lastArriveDay = bobArriveDay;
            firstArriveDay = aliceArriveDay;
        }

        // determining leave order
        if(firstLeaveMonth == lastLeaveMonth){
            firstLeaveDay = min(aliceLeaveDay, bobLeaveDay);
            lastLeaveDay = max(aliceLeaveDay, bobLeaveDay);
        } else if(firstLeaveMonth == aliceLeaveMonth){
            firstLeaveDay = aliceLeaveDay;
            lastLeaveDay = bobLeaveDay;
        } else{
            firstLeaveDay = bobLeaveDay;
            lastLeaveDay = aliceLeaveDay;
        }

        // If overlap only happens in one month, simple calculation (test for day overlap)
        if(firstLeaveMonth == lastArriveMonth){
            if(firstLeaveDay < lastArriveDay){
                return 0;
            } else return firstLeaveDay - lastArriveDay + 1;
        }

        int overlapDays = daysPerMonth[lastArriveMonth-1] - (lastArriveDay-1);
        int diff = 1;
        // add all the days of months inbetween the arrival and departure month
        while(lastArriveMonth + diff < firstLeaveMonth){
            overlapDays += daysPerMonth[lastArriveMonth-1+diff];
            diff++;
        }
        // add the days of the month of departure, before the actual departure day
        overlapDays += firstLeaveDay;
        return overlapDays;
    }
};
