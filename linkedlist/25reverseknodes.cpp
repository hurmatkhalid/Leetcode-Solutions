// Given the head of a linked list, reverse the nodes of 
// the list k at a time, and return the modified list.
// k is a positive integer and is less than or equal 
// to the length of the linked list.
//  If the number of nodes is not a multiple of k 
// then left-out nodes, in the end, should remain as it is.
// You may not alter the values in the list's nodes, only nodes themselves may be changed.

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
        if(head==NULL || k==1)   return head;
        ListNode* counter= head;
        int count=0;
        while(counter!=NULL){
            count++;
            counter = counter->next;
        }
        ListNode* dummy= new ListNode(0);
        dummy->next= head;
        ListNode* current = dummy, *nex= dummy, *prev= dummy;

        while(count>=k){
            current = prev->next;
            nex = current->next;
            for(int i=1; i<k; i++){
                current->next= nex->next;
                nex->next= prev->next;
                prev->next= nex;
                nex= current->next;
            }
            prev= current;
            count-=k;
        }
        return dummy->next;
    }
};