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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;
        int carry=0;
        while(l1!=nullptr || l2!=nullptr||carry){
          int sum=0;
          
          if(l1!=nullptr){
            sum=sum+l1->val;
            l1=l1->next;
          }
          if(l2!=nullptr){
            sum=sum+l2->val;
            l2=l2->next;
          }
          sum+=carry;
          carry=sum/10;

          ListNode* ans=new ListNode(sum%10);
          curr->next=ans;
          curr=curr->next;
        }

        // if(carry){
        //     ListNode* remCarry=new ListNode(carry);
        //     curr->next=remCarry;
        // }

        return dummy->next;
    }
};