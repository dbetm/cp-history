# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        """
        Time: O(n), where n = 10e4
        Space: O(1)
        """
        if head is None or head.next is None:
            return False

        limit_ = 10e4
        cont = 0

        tmp = head

        while tmp:
            cont += 1

            if cont > limit_:
                return True

            tmp = tmp.next

        return False

    def hasCycle2(self, head: Optional[ListNode]) -> bool:
        """
        Time: O(n)
        Space: O(n)
        """
        if head is None or head.next is None:
            return False

        visited = set()
        tmp = head

        visited.add(id(tmp))

        while tmp:
            tmp = tmp.next

            if id(tmp) in visited:
                return True
            
            visited.add(id(tmp))

        return False

    def hasCycle3(self, head: Optional[ListNode]) -> bool:
        """
        Time: O(n)
        Space: O(1)
        """
        if head is None:
            return False

        walker = head
        runner = head

        while runner.next and runner.next.next:
            walker = walker.next
            runner = runner.next.next
            # at some point will match
            if walker == runner:
                return True

        return False