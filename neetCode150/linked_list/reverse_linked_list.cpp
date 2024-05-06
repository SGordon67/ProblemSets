/*
PROBLEM (easy)
Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
  
Example 2:
Input: head = [1,2]
Output: [2,1]
  
Example 3:
Input: head = []
Output: []

Constraints:
The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
*/
/*
SOLUTION
Go node by node, from head to tail.
Make the current node point to the previous node, then move your duo of nodes forward one node.
Need to grab next node before rerouting the link to not lose the connection to the next node.

Initial solution I used a stack to grab the values, then just reassign off the stack going through the linked list again.
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
    ListNode* reverseList(ListNode* head) {
        ListNode* node = head;
        ListNode* pnode = NULL;
        while( node != NULL ){
            ListNode* next = node->next; 
            node->next = pnode;
            pnode = node;
            node = next;
        }
        return pnode;
    }
};
