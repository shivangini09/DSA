class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        // fast ko n steps aage se dauda rahe lol
        for(int i=0; i<n; i++){
            fast=fast->next;
        }
        // edge case
        if(fast==NULL){
            ListNode* newhead = head->next;
            delete(head);
            return newhead;
        }
        ListNode* slow = head;
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* delnode = slow->next;
        slow->next=delnode->next;
        delete delnode;
        
    return head;

    }
};
