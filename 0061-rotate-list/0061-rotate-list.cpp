class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;

        ListNode* old_tail = head;
        int length = 1;
        while (old_tail->next) {
            old_tail = old_tail->next;
            length++;
        }

        old_tail->next = head;

        int new_tail_position = length - k % length - 1;
        ListNode* new_tail = head;
        for (int i = 0; i < new_tail_position; ++i) {
            new_tail = new_tail->next;
        }
        ListNode* new_head = new_tail->next;

        new_tail->next = nullptr;

        return new_head;
    }
};
