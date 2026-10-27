class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* mid=slow;
        ListNode* prev=NULL;
        ListNode* next=NULL;

        while(slow!=NULL){
            next=slow->next;
            slow->next=prev;
            prev=slow;
            slow=next;
        }

        ListNode* first=head;
        ListNode* second=prev;

        while(second!=NULL){
            if(first->val!=second->val){
                return false;
            }
            first=first->next;
            second=second->next;
        }

        return true;
    }
};