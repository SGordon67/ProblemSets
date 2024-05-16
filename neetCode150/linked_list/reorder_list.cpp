/*
PROBLEM (medium)
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4]
Output: [1,4,2,3]

Example 2:
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]

Constraints:
The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000
*/
/*
SOLUTION(S)
Runtime efficient solution is provided.
This uses a vector of nodes.
Insert the last node in the list inbetween each two nodes in the beginning of the list.
This creates the desired outcome.

The solution commented out is my first attempt.
It works but is slow because it searches for the last node in each iteration causing n^2 time complexity.
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
    void reorderList(ListNode* head) {
        if(head == nullptr) return;
        if(head->next == nullptr) return;

        vector<ListNode*> nodes;
        ListNode* iterate = head;
        int size = 0;
        while(iterate != nullptr){
            nodes.push_back(iterate);
            iterate = iterate->next;
            size++;
        }

        int prevNodeIndex = 0;
        int currNodeIndex = 1;
        int lastNodeIndex = size-1;

        while(currNodeIndex < lastNodeIndex){
            ListNode* prevNode = nodes[prevNodeIndex];
            ListNode* currNode = nodes[currNodeIndex];
            ListNode* lastNode = nodes[lastNodeIndex];

            prevNode->next = lastNode;
            lastNode->next = currNode;
            nodes[lastNodeIndex-1]->next = nullptr;

            lastNodeIndex--;
            prevNodeIndex++;
            currNodeIndex++;
        }

        // COMMENTED OUT SOLUTION
        // if(head == nullptr) return;
        // if(head->next == nullptr) return;

        // int size = 0;
        // ListNode* it = head;
        // while(it != nullptr){
        //     size++;
        //     it = it->next;
        // }
        
        // it = head;
        // int index = 0;
        // bool getEnd = true;
        // while(index < size-1){
        //     if(!getEnd){
        //         it = it->next;
        //         index++;
        //         getEnd = true;
        //         continue;
        //     }

        //     ListNode* helper = it;
        //     int placesToMove = (size - index) - 1;
        //     while(placesToMove > 1){
        //         helper = helper->next;
        //         placesToMove--;
        //     }
        //     if(index < size-2){
        //         helper->next->next = it->next;
        //         it->next = helper->next;
        //         helper->next = nullptr;
        //     }
            
        //     index++;
        //     it = it->next;
        //     getEnd = false;
        // }
        // return;
    }
};
