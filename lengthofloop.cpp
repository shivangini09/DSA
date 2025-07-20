/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    int findloop(Node *fast,Node *slow){
        fast=fast->next;
        int count = 1;
        while(fast!=slow){
            count++;
            fast=fast->next;
        }
        return count;
    }
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        Node *slow=head;
        Node *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                return findloop(fast,slow);
            }
        }
        return 0;
    }
};