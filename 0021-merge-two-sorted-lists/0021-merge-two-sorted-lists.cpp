
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy; 

     
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1; 
                list1 = list1->next; // Move to the next node in list1
            } else {
                tail->next = list2; // Attach list2 node to the merged list
                list2 = list2->next; // Move to the next node in list2
            }
            tail = tail->next; // Move tail to the last node in the merged list
        }

        // Attach the remaining nodes from list1 or list2
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        // Store the result list starting from dummy->next
        ListNode* mergedHead = dummy->next;

        // Clean up the dummy node
        delete dummy;

        return mergedHead;
    }
};
