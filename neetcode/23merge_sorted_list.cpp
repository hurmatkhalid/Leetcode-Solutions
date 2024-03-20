// You are given an array of k linked-lists lists, 
// each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.


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


// naive and doesnt handle edge cases well like [[],[]]
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size()==0) {
            return NULL;
        }
        if(lists.size()==1){
            return lists[0];
        }
        int k = lists.size();
        vector<int>arr;
        for(int i =0; i<k; i++){
            ListNode*temp= lists[i];
            while(temp!=NULL){
                arr.push_back(temp->val);
                temp=temp->next;
            }
        }
        sort(arr.begin(), arr.end());
        ListNode* head = new ListNode(arr[0]);
        ListNode*temp= head;
        for(int i=1; i<arr.size(); i++){
            temp->next= new ListNode(arr[i]);
            temp= temp->next;
        }
        return head;
    }
};