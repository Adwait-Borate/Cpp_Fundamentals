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
        if (head == nullptr || head->next == nullptr) return head; // Return if list is empty or has one element

        ListNode* temp = head;  // Pointer to traverse the linked list

        while (temp != nullptr && temp->next != nullptr) {
            if (temp->val == temp->next->val) { // If duplicate found
                ListNode* newNode = temp->next;  // Duplicate node
                temp->next = newNode->next;      // Bypass the duplicate node
                delete newNode;                 // Delete the duplicate node
            } else {
                temp = temp->next; // Move to the next node if no duplicate
            }
        }

        return head;
    }
};