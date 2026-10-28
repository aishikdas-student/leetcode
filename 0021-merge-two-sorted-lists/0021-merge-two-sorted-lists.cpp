class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ptr1=list1;
        ListNode* ptr2=list2;
        ListNode* head=new ListNode();
        ListNode* ptr3=head;

        while(ptr1!=NULL && ptr2!=NULL){
            if(ptr1->val <= ptr2->val){
                ptr3->next=new ListNode(ptr1->val); //creates a new node and links
                ptr1=ptr1->next;
                ptr3=ptr3->next;
            }else{
                ptr3->next=new ListNode(ptr2->val);
                ptr3=ptr3->next;
                ptr2=ptr2->next;
            }
        }
        while(ptr1!=NULL){
            ptr3->next=new ListNode(ptr1->val);
            ptr1=ptr1->next;
            ptr3=ptr3->next;
        }
        while(ptr2!=NULL){
            ptr3->next=new ListNode(ptr2->val); //we have to write this so
                                                //that we create a next node such that we can do ptr3=ptr3->next
            ptr2=ptr2->next;
            ptr3=ptr3->next;
        }
        ListNode* ans=head->next;
        delete head;
        return ans;
    }
};