from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        if not head:
            return head

        tmp = head
        prev = None

        while tmp and tmp.val == val:
            prev = tmp
            tmp = tmp.next
            head = tmp

        # remove intermediate elements
        while tmp:
            if tmp.val == val:
                prev.next = tmp.next
            else:
                prev = tmp
            tmp = tmp.next

        return head