// Given the head of a linked list, rotate the list to the right by k places

// brute force - TLE
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL|| head->next==NULL)    return head;
        for(int i =0; i<k; i++){
            ListNode* temp= head;
            while(temp->next->next!=NULL)   temp= temp->next;
            ListNode* end = temp->next;
            end->next= head;
            temp->next= NULL;
            head= end;
        }
        return head;
    }
};

// slightly better
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL|| head->next==NULL)    return head;
        ListNode*countTemp=head;
        int count=1;
        while(countTemp->next!=NULL){
            countTemp= countTemp->next;
            count++;
        }
        k = k%count;
        for(int i =0; i<k; i++){
            ListNode* temp= head;
            while(temp->next->next!=NULL)   temp= temp->next;
            ListNode* end = temp->next;
            end->next= head;
            temp->next= NULL;
            head= end;
        }
        return head;
    }
};
// best
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL|| head->next==NULL||k==0)    return head;
        ListNode*curr=head;
        int count=1;
        while(curr->next!=NULL){
            curr= curr->next;
            count++;
        }
        curr->next= head;
        k = k%count;
        k = count - k;
        while(k--){
            curr= curr->next;
        }
        head=curr->next;
        curr->next=NULL;
        return head;
    }
};
