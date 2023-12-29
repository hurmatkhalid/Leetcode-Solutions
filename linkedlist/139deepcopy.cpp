// A linked list of length n is given such that each node
//  contains an additional random pointer, 
// which could point to any node in the list, or null.

// naive
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
        unordered_map <Node*, Node*> mpp;
        Node*temp = head;
        while(temp!=NULL){
            Node *newNode= new Node(temp->val);
            mpp[temp]= newNode;
            temp = temp->next;
        }
        temp= head;
        while(temp!=NULL){
            Node*node = mpp[temp];
            node->next = (temp->next!=NULL)? mpp[temp->next]:NULL;
            node->random = (temp->random!=NULL)? mpp[temp->random]:NULL;
            temp= temp->next;
        }
        return mpp[head];
    }
};

// better
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
        Node *temp= head;
        while(temp!=NULL){
            Node *newNode = new Node(temp->val);
            newNode->next= temp->next;
            temp->next= newNode;
            temp = temp->next->next;
        }
        temp = head;
        while(temp!=NULL){
            if(temp->random!=NULL){
                temp->next->random= temp->random->next;
            }
            temp= temp->next->next;
        }
        Node* dummy = new Node(0);
        temp= head;
        Node*itr= dummy;
        Node* nex;
        while(temp!=NULL){
            nex= temp->next->next;
            itr->next= temp->next;
            temp->next = nex;
            temp = temp->next;
            itr= itr->next;
        }
        return dummy->next;
    }
};