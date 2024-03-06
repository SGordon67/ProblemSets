/*
PROBLEM
Given a linked list, swap every two adjacent nodes and return its head. 
You must solve the problem without modifying the values in the list's nodes 
(i.e., only nodes themselves may be changed.)

Example 1:
Input: head = [1,2,3,4]
Output: [2,1,4,3]

Example 2:
Input: head = []
Output: []

Example 3:
Input: head = [1]
Output: [1]

Constraints:
The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100

Definition for singly-linked list:
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
*/
/*
SOLUTION
Decided to solve iteratively instead of the recommended recursive approach to see if it could be done easily.
  Was able to implement, and is more efficient in time and memory than a recursive solution.

Go through the linked list two nodes at a time (also keep track of the previous last node):
  Swap the two nodes.
  Make sure the previous node updates to point at the swapped first node.
Once you reach the end, return the head.
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr) return head;
        if(head->next == nullptr) return head;

        ListNode* nh = head->next;

        ListNode* nOne = head;
        ListNode* nTwo = head->next;
        ListNode* last = nullptr;
        bool endFound = false;
        while (!endFound){
            nOne->next = nTwo->next;
            nTwo->next = nOne;
            if(nOne->next == nullptr){
                endFound = true;
            } else if(nOne->next->next == nullptr){
                endFound = true;
            }
            if(last != nullptr){
                last->next = nTwo;
            }
            if(endFound) break;
            last = nOne;
            nOne = nOne->next;
            nTwo = nOne->next;
        }
        return nh;
    }
};
