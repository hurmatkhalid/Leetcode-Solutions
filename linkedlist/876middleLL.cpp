// Given the head of a singly linked list, return the middle node of the linked list.
// If there are two middle nodes, return the second middle node.

// naive solution
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp= head;
        int count=0;
        while(temp){
            count++;
            temp= temp->next;
        }
        temp = head;
        for(int i =0; i<count/2; i++){
            temp= temp->next;
        }
        return temp;
    }
};
//optimal   TORTOISE AND HARE ALGORITHM
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head, *fast= head;
        while(fast && fast->next)   
            slow = slow->next, fast = fast->next->next;
        return slow;
    }
};