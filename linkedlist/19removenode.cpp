// Given the head of a linked list, remove the nth node from the end of the list and return its head.
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
        int size=0;
        int count=0;
        ListNode*temp= head;
        while(temp!=nullptr){
            size++;
            temp=temp->next;
        }
        temp=head;
        if(size==n){
            head=head->next;
            delete temp;
            return head;
        }
        while(temp!=NULL){
            count++;
            if(count== size-n) {
                temp->next= temp->next->next;
                break;
            }    
            temp= temp->next;
        }
        return head;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *start = new ListNode();
        start->next= head;
        ListNode *fast= start;
        ListNode *slow= start;
        for(int i=0; i<n; i++){
            fast= fast->next;
        }
        while(fast->next!=NULL){
            fast= fast->next;
            slow= slow->next;
        }
        slow->next= slow->next->next;
        return start->next;
    }

};