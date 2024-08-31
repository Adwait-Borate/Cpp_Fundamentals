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
#include <queue>

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;  // If list has 0 or 1 node, return as is

        std::queue<ListNode*> oddQueue;
        std::queue<ListNode*> evenQueue;

        ListNode* current = head;
        bool isOdd = true;  // Flag to alternate between odd and even nodes

        // Separate odd and even nodes into two queues
        while (current != nullptr) {
            if (isOdd) {
                oddQueue.push(current);  // Push odd indexed nodes
            } else {
                evenQueue.push(current);  // Push even indexed nodes
            }
            current = current->next;  // Move to the next node
            isOdd = !isOdd;  // Alternate the flag
        }

        // Reconstruct the linked list
        ListNode* newHead = nullptr;
        ListNode* tail = nullptr;

        // First, add all odd nodes
        while (!oddQueue.empty()) {
            if (newHead == nullptr) {
                newHead = oddQueue.front();  // Initialize the new head
                tail = newHead;  // Initialize the tail
            } else {
                tail->next = oddQueue.front();  // Link the odd nodes
                tail = tail->next;  // Move the tail
            }
            oddQueue.pop();
        }

        // Next, add all even nodes
        while (!evenQueue.empty()) {
            tail->next = evenQueue.front();  // Link the even nodes
            tail = tail->next;  // Move the tail
            evenQueue.pop();
        }

        // End the list
        tail->next = nullptr;

        return newHead;
    }
};
