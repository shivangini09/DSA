class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return NULL;  // ⚠️ Don't delete head yourself
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        prev->next = slow->next;
        // ⚠️ Don't delete slow

        return head;
    }
};
