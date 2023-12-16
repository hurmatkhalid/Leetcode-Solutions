// Given the heads of two singly linked-lists headA and headB,
//  return the node at which the two lists intersect. If the two 
// linked lists have no intersection at all, return null.
// For example, the following two linked lists begin to intersect at node c1:

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// naive solution
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*tempA= headA;
        ListNode*tempB= headB;
        map<ListNode*, int>mpp;
        while(tempA!=NULL){
            mpp[tempA]= tempA->val;
            tempA= tempA->next;
        }
        while(tempB!=NULL){
            if(mpp.find(tempB)!=mpp.end()){
                return tempB;
            }
            tempB= tempB->next;
        }
        return NULL;
    }
};

// BETTER SOLUTION
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        int countA=0, countB=0;
        while(tempA!=NULL){
            tempA= tempA->next;
            countA++;
        }
        while(tempB!=NULL){
            tempB= tempB->next;
            countB++;
        }
        if(countA>countB){
            int diff= countA-countB;
            while(diff>0){
                headA=headA->next;
                diff--;
            }
        }else{
            int diff= countB-countA;
            while(diff>0){
                headB=headB->next;
                diff--;
            }
        }
        while(headA!=NULL || headB!=NULL){
            if(headA==headB){
                return headA;
            }
            headA= headA->next;
            headB= headB->next;
        }
        return NULL;
    }
};

// best
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB== NULL) return NULL;
        ListNode*tempA= headA;
        ListNode*tempB= headB;
        while(tempA!=tempB){
            tempA = tempA==NULL? headB: tempA->next;
            tempB = tempB==NULL? headA: tempB->next; 
        }
        return tempA;
    }
};