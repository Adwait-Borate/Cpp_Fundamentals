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
        ListNode* temp=head;
        ListNode* prev=NULL;
        for(int i=0;i<n;i++){
            temp=temp->next;
        }

        if(temp==NULL){
            ListNode* result=head->next;
            delete(head);
            return result;
        }

        prev=head;
        while(temp!=NULL && temp->next!=NULL){
            prev=prev->next;
            temp=temp->next;
        }
        prev->next=prev->next->next;
        return head;
    }
};