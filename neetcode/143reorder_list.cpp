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
    void reorderList(ListNode* head) {
        // find middle of the list
        ListNode*slow= head, *fast= head->next;
        while(fast and fast->next){
            slow= slow->next;
            fast= fast->next->next;
        }
        // reversing the list
        ListNode*second= slow->next, *prev = NULL;
        slow->next= NULL;
        while(second){
            ListNode*temp=second->next;
            second->next=prev;
            prev= second;
            second= temp;
        }
        // merge the two lists
        ListNode*first= head;
        second= prev;
        
        while(second){
            ListNode*temp1= first->next, *temp2= second->next;
            first->next=second;
            second->next= temp1;
            first= temp1;
            second=temp2;
        }
    }
};