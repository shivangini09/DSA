class Solution {
public:
    #tortoiseharemethod
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    # //     int count = 0;
    # //     ListNode* temp = head;

    # //     // Count the total number of nodes
    # //     while (temp != NULL) {
    # //         count++;
    # //         temp = temp->next;
    # //     }

    # //     // Reset temp to the head and calculate the middle index
    # //     temp = head;
    # //     int mid = count / 2;

    # //     // Traverse to the middle node
    # //     while (mid > 0) {
    # //         temp = temp->next;
    # //         mid--;
    # //     }

    # //     return temp; // Return the middle node
    # // }

