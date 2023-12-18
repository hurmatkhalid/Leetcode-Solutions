// Given the head of a singly linked list, return true if it is a 
// palindrome or false otherwise.

// naive approach
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)    return true;
        vector<int>v1;
        while(head!=NULL){
            v1.push_back(head->val);
            head=head->next;
        }
        int n = v1.size();
        int start= 0;
        int end= n-1;
        while(start<end){
            if(v1[start]!=v1[end])  return false;
            start++;
            end--;
        }
        return true;
    }
};
// best
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
    ListNode* reverselist(ListNode* head){
        ListNode* prev=NULL, *nex= NULL;
        while(head!=NULL){
            nex=head->next;
            head->next=prev;
            prev=head;
            head=nex;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)      return true;
        ListNode *slow=head, *fast= head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow= slow->next;
            fast= fast->next->next;
        }
        slow->next=reverselist(slow->next);
        slow= slow->next;
        while(slow!=NULL){
            if(head->val!=slow->val){
                return false;
            }
            head=head->next;
            slow=slow->next;
        }
    return true;
    }
};