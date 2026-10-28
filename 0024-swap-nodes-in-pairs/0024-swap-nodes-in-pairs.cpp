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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count=0;
        ListNode* temp=head;
        while(count<k){        //check if k nodes exist
            if(temp==NULL){
                return head;   // if not exist no change
            }
            temp=temp->next;
            count++;
        }
        //now call for rest of LL
        ListNode * prev =reverseKGroup(temp,k);
        //reverse current group
        ListNode* next=NULL;
        temp=head; //head of curr grp
        int cnt=0;
        while(cnt<k){
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
            cnt++;
        }
        return prev;
    }
    ListNode* swapPairs(ListNode* head) {
        head=reverseKGroup(head,2);
        return head;
    }
};