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
    
    ListNode* deleteDuplicates(ListNode* head) {
        set<int> s;
        if(head==NULL){
            return NULL;
        }
        ListNode* ptr=head;
        s.insert(ptr->val);
        while(ptr->next!=NULL){
            ListNode* nextnode=ptr->next;
            if(s.find(nextnode->val)!=s.end()){ //duplicate present
                ptr->next=nextnode->next;
                delete nextnode;         //dont inc ptr if duplicate present
            }else{
                s.insert(nextnode->val);
                ptr=ptr->next;
            }
            
        }
        return head;


        
    }
};