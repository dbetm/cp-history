from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if not head or not head.next:
            return None

        cached_list = list()

        # [1, 2, 3, 4, 5], (5 - 2) - 1 = 2

        # [1, 2], (2 - 2) - 1 = -1, if it0's < 0, then return 2

        tmp = head
        while tmp:
            cached_list.append(tmp)
            tmp = tmp.next

        sz = len(cached_list)
        x = sz - n - 1

        if x < 0:
            return cached_list[sz - n + 1]

        cached_list[x].next = cached_list[x + 1].next

        return cached_list[0]

