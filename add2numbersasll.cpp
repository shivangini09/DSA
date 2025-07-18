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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* dummy = new ListNode();          // initiating a dummy node cause we have to give a linked list
        ListNode* temp = dummy;                    // temp node
        while(l1!=NULL || l2!=NULL || carry==1){
            int sum=0;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }         
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;       // Changing the carry 
            ListNode* newnode = new ListNode(sum%10);
            temp->next = newnode;
            temp=temp->next;
        }
        return dummy->next;        // returning the linked list
        
    }
};