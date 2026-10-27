class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ptr = head;
        ListNode* prev = NULL;

        while(ptr != NULL) {
            if(ptr->val == val) {
                ListNode* temp = ptr;

                if(ptr == head) {
                    head = head->next;
                    ptr = head;
                }
                else {
                    prev->next = ptr->next;
                    ptr = ptr->next;
                }

                delete temp;
            }
            else {
                prev = ptr;
                ptr = ptr->next;
            }
        }

        return head;
    }
};