/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        unordered_map<Node*,Node*> m; //<oldnode,newnode>
        Node* oldTemp=head;
        Node* newhead = new Node(head->val);//created the first node
        Node*newTemp=newhead;
        m[head]=newhead;  //added the first node to hashmap
        oldTemp=oldTemp->next; //hence move oldtempm as  well
        while(oldTemp!=NULL){          //first make the connections of next
            Node* copynode=new Node(oldTemp->val);
            newTemp->next=copynode;
            m[oldTemp]=copynode; //store oldnode with newnode
            oldTemp=oldTemp->next;
            newTemp=newTemp->next;
        }
        oldTemp=head;
        newTemp=newhead;
        while(oldTemp!=NULL){
            newTemp->random=m[oldTemp->random]; //newtemp->random= newnode of oldtemp->random
            newTemp=newTemp->next;
            oldTemp=oldTemp->next;
            
        
        }
        return newhead;
         
    }
};