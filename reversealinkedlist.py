# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def reverseList(self, head):
        prev = None 
        temp = head
        while temp != None:
            # newhead = ListNode(-1)
            front = ListNode(-1)
            front = temp.next
            temp.next = prev
            prev = temp
            temp = front 
        return prev