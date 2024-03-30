/*
PROBLEM
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. 
Return the linked list sorted as well.

Example 1:
Input: head = [1,1,2]
Output: [1,2]

Example 2:
Input: head = [1,1,2,3,3]
Output: [1,2,3]

Constraints:
The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
*/
/*
SOLUTION
Traverse the tree from head to tail.
Keep track of the values I've seen using a map. Could probably use unordered set instead for space effeciency.
If the next value in the list is already in the map, attach the current node the node after the next node.
Return the head after since it is done in place.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return head;
        map<int, int> m;

        ListNode* n = head;
        m[head->val]++;
        while(n->next != nullptr){
            int nextVal = n->next->val;
            m[nextVal]++;
            if(m[nextVal] >= 2){
                n->next = n->next->next;
            } else{
                n = n->next;
            }
        }
        return head;
    }
};
