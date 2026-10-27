class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){    //find mid
            slow=slow->next;
            fast=fast->next->next;          //1-2-3-2-1
        }

        ListNode* mid=slow;
        ListNode* prev=NULL;
        ListNode* next=NULL;

        while(slow!=NULL){
            next=slow->next;        //reverse from mid to end
            slow->next=prev;        //1-2-3-1-2
            prev=slow;
            slow=next;
        }

        ListNode* first=head;
        ListNode* second=prev;
 
        while(second!=NULL){           //now compare both halves if equal true else false
            if(first->val!=second->val){
                return false;
            }
            first=first->next;
            second=second->next;
        }

        return true;
    }
};