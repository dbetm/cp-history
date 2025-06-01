from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None



class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None

        visited = set()
        tmp = head

        visited.add(id(tmp))

        while tmp:
            tmp = tmp.next

            if id(tmp) in visited:
                return tmp

            visited.add(id(tmp))

        return None
    
    def detectCycle2(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """
        Time O(n)
        Space: O(1)
        Look for the math behind this, it's necessary"""
        if head is None:
            return None

        walker = head
        runner = head
        has_cycle = False

        while runner.next and runner.next.next:
            walker = walker.next
            runner = runner.next.next

            if runner == walker:
                has_cycle = True
                break
        
        if not has_cycle:
            return None

        walker = head

        while walker != runner:
            walker = walker.next
            runner = runner.next

        return walker
