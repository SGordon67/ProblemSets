/*
PROBLEM (medium)
Given the head of a linked list head, in which each node contains an integer value.
Between every pair of adjacent nodes, insert a new node with a value equal to the greatest common divisor of them.
Return the linked list after insertion.
The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.

Example 1:
Input: head = [18,6,10,3]
Output: [18,6,6,2,10,1,3]
Explanation: The 1st diagram denotes the initial linked list and the 2nd diagram denotes the linked list after inserting the new nodes (nodes in blue are the inserted nodes).
- We insert the greatest common divisor of 18 and 6 = 6 between the 1st and the 2nd nodes.
- We insert the greatest common divisor of 6 and 10 = 2 between the 2nd and the 3rd nodes.
- We insert the greatest common divisor of 10 and 3 = 1 between the 3rd and the 4th nodes.
There are no more adjacent nodes, so we return the linked list.

Example 2:
Input: head = [7]
Output: [7]
Explanation: The 1st diagram denotes the initial linked list and the 2nd diagram denotes the linked list after inserting the new nodes.
There are no pairs of adjacent nodes, so we return the initial linked list.

Constraints:
The number of nodes in the list is in the range [1, 5000].
1 <= Node.val <= 1000
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // function to find the greatest common divisor
    int gcd(int a, int b){
        int divisor = min(a, b);
        while(divisor > 1){
            // start with smaller of two values, and decrease from there
            // if divisor goes into both numbers then return
            if(a % divisor == 0 && b % divisor == 0) return divisor;
            divisor--;
        }
        // return 1 if no other divisor was found
        return 1;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next == nullptr) return head;

        ListNode* n1 = head;
        ListNode* n2 = head->next;

        while(n2 != nullptr){
            // find gcd
            int tgcd = gcd(n1->val, n2->val);
            // create new node, link it to left and right
            ListNode* nn = new ListNode(tgcd, n2);
            n1->next = nn;

            // update n1 and n2
            n1 = n2;
            n2 = n2->next;
        }
        return head;
    }
};
