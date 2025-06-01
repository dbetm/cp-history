from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def get_len(self, head: Optional[ListNode]) -> int:
        cont = 0

        while head:
            cont += 1
            head = head.next

        return cont

    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or not head.next:
            return head

        n = self.get_len(head)
        k = k % n

        if k == 0:
            return head

        index = n - k
        ref = head
        cont = 0

        while ref:
            if cont == (index - 1): # subtract 1 to get prev 
                break
            cont += 1
            ref = ref.next

        new_head = ref.next
        tail = new_head

        while tail.next:
            tail = tail.next if tail.next else tail

        tail.next = head
        ref.next = None

        return new_head