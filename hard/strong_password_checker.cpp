/*
PROBLEM (hard)
A password is considered strong if the below conditions are all met:
It has at least 6 characters and at most 20 characters.
It contains at least one lowercase letter, at least one uppercase letter, and at least one digit.
It does not contain three repeating characters in a row (i.e., "Baaabb0" is weak, but "Baaba0" is strong).
Given a string password, return the minimum number of steps required to make password strong. if password is already strong, return 0.

In one step, you can:
Insert one character to password,
Delete one character from password, or
Replace one character of password with another character.

Example 1:
Input: password = "a"
Output: 5

Example 2:
Input: password = "aA1"
Output: 3

Example 3:
Input: password = "1337C0d3"
Output: 0

Constraints:
1 <= password.length <= 50
password consists of letters, digits, dot '.' or exclamation mark '!'.
*/
class Solution {
public:
    int strongPasswordChecker(string s) {
        bool lower = false;
        bool upper = false;
        bool digit = false;
        
        int repeating = 0;
        
        int n = s.size();
        
    		//We actually dont need a priority queue here because
    		//The numbers are going to be < 3 
        priority_queue<int> toRemove;
        
        for(int i = 0; i < n;) {
            //Check if character is lowercase, uppercase, or digit and set those to true
            char c = s[i];
            if(48 <= c && c <= 57) {
                digit = true;
            } else if(65 <= c && c <= 90) {
                upper = true;
            } else if(97 <= c && c <= 122) {
                lower = true;
            }
            
            
            //count how many repeating numbers we have
            int counter = 1;
            while(i + counter < n && s[i + counter] == s[i]) {
                counter++;
            }
            
            //number of repeat errors goes up by 1 for every 3 repeating
            repeating += (counter) / 3;
            
            //if we have a repeat error than push to a heap the number of deletions we need to 
            //remove a repeat error
            if(counter > 2 && counter % 3 != 2) {
                toRemove.push(-((counter % 3) + 1));
            }
            
            i += counter;
        }
        
        //count missing cases
        int toAdd = !lower + !upper + !digit;
        
        //get size error. 0 if there are no errors
        int toSize = 0;
        if(n > 20) {
            toSize = 20 - n;
        } else if(n < 6) {
            toSize = 6 - n;
        }
        
        if(toSize < 0) {
            //case n > 20
            //remove easy repeat errors with < 3 deletions required
            int tmpSize = toSize;
            while(toRemove.size()) {
                if(tmpSize <= toRemove.top()) {
                    tmpSize -= toRemove.top();
                    toRemove.pop();
                    repeating--;
                } else {
                    break;
                }
            }
            
            //remove repeat errors that require 3 deletions
            while(repeating && tmpSize <= -3) {
                tmpSize += 3;
                repeating--;
            }
            
            //if we have any case errors we can merge them with
            //repeat errors
            return max(toAdd, repeating) - toSize;
            
        } else {
            //case n <= 20
            //the error is simply the max becauses we can merge
            //every error with pretty much no consequence
            return max(toSize, max(toAdd, repeating));
        }
    }
};
