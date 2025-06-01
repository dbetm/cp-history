from typing import Optional

# Definition for singly-linked list.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        carry = 0
        result = None
        head = None

        if l1 and l2:
            sum_ = (l1.val + l2.val) % 10
            carry = (l1.val + l2.val) // 10
            result = ListNode(sum_)
            head = result
            l1 = l1.next
            l2 = l2.next
        elif l1:
            result = ListNode(l1.val)
            head = result
            l1 = l1.next
        elif l2:
            result = ListNode(l2.val)
            head = result
            l2 = l2.next
        
        while l1 or l2:
            if l1 and l2:
                sum_ = (l1.val + l2.val + carry) % 10
                carry = (l1.val + l2.val + carry) // 10
                result.next = ListNode(sum_)
                l1 = l1.next
                l2 = l2.next
                result = result.next
            elif l1:
                sum_ = (l1.val + carry) % 10
                carry = (l1.val + carry) // 10
                result.next = ListNode(sum_)
                l1 = l1.next
                result = result.next
            elif l2:
                sum_ = (l2.val + carry) % 10
                carry = (l2.val + carry) // 10
                result.next = ListNode(sum_)
                l2 = l2.next
                result = result.next

        if carry > 0:
            result.next = ListNode(carry)

        return head