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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // using two pointers
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val<=temp2->val){
                temp->next = temp1;
                temp1 = temp1->next; // move temp1 to compare
            }
            else{
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next; // temp sorted, move on to the next
        }
        // agar temp1 bacha hai
        while(temp1!=NULL){
            temp->next = temp1;
            temp1 = temp1->next;
            temp=temp->next;
        }
        // agar temp two bacha hai
        while(temp2!=NULL){
            temp->next = temp2;
            temp2 = temp2->next;
            temp=temp->next;
        }
        return dummy->next;
        
        
    }
};