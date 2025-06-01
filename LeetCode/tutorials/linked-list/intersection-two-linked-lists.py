# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        """Proposal
        Time: O(n)
        Space: O(n)
        """
        tmp1, tmp2 = headA, headB
        visited = set()

        while tmp1:
            visited.add(id(tmp1))
            tmp1 = tmp1.next
        

        while tmp2:
            if id(tmp2) in visited:
                return tmp2
            tmp2 = tmp2.next

        return None

    def getIntersectionNode2(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        """My second proposal
        Time: O(n)
        Space: O(1)
        """
        tmp1, tmp2 = headA, headB
        m, n = 0, 0

        while tmp1:
            m += 1
            tmp1 = tmp1.next

        while tmp2:
            n += 1
            tmp2 = tmp2.next

        if m > n:
            x = m
            y = n
            largest = headA
            shortest = headB
        else:
            x = n
            y = m
            largest = headB
            shortest = headA

        delta = x - y
        while delta > 0:
            delta -= 1
            largest = largest.next

        while largest != shortest:
            largest = largest.next
            shortest = shortest.next

        return largest