/*
PROBLEM 
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]

Constraints:
The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 
Follow up: Could you do this in one pass?
  yes, but I would construct a new linked list in the process enlarging the memory requirement.
*/
/*
SOLUTION
Get the length of the linked list.
Calculate which node from the front needs to be removed.
Make it so that the node that points to the node to be removed, now points to the node after the node to be removed.
Handle any edge cases accoringly such as length of list equals 0.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* it = head;
        while(it->next != NULL){
            it = it->next;
            len++;
        }
        len++;
        it = head;
        if(len == 1 || n == len) return it->next;

        it = head;
        int fromStart = len - n;
        for(int i = 1; i < fromStart; i++){
            it = it->next;
        }
        it->next = it->next->next;
        return head;
    }
};
