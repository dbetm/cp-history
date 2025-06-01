from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def get_len(self, head: Optional[ListNode]) -> int:
        cont = 0

        tmp = head
        while tmp:
            cont += 1
            tmp = tmp.next

        return cont

    def reverse_linked_list(self, head: ListNode) -> ListNode:
        if not head:
            return None

        tmp = head.next
        original_head = head

        while tmp:
            next_ = tmp.next

            tmp.next = head
            head = tmp
            tmp = next_

        original_head.next = None

        return head

    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        if not head or not head.next:
            return True

        length = self.get_len(head)

        if length & 1: # odd
            idx = (length // 2) + 1
        else: # even
            idx = length // 2

        cont = 0
        tmp = head
        ref = None
        prev_ref = None

        while tmp:
            if (cont + 1) == idx:
                prev_ref = tmp
            if cont == idx:
                ref = tmp
                break

            cont += 1
            tmp = tmp.next

        assert ref is not None

        second_half = self.reverse_linked_list(ref)
        prev_ref.next = second_half

        tmp = head
        while second_half:
            if second_half.val != tmp.val:
                return False

            second_half = second_half.next
            tmp = tmp.next

        return True

