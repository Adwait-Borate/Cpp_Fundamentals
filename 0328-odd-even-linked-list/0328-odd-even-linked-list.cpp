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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* odd = head;             // Pointer to the odd list
        ListNode* even = head->next;      // Pointer to the even list
        ListNode* evenHead = even;        // Head of the even list

        // Rearrange nodes in odd and even positions
        while(even != nullptr && even->next != nullptr) {
            odd->next = even->next;       // Point odd to the next odd node
            odd = odd->next;              // Move odd pointer forward

            even->next = odd->next;       // Point even to the next even node
            even = even->next;            // Move even pointer forward
        }

        odd->next = evenHead;  // Attach even list after the odd list
        return head;
    }
};
