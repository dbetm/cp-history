
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    
    def __str__(self):
        return str(self.val)


class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next or not head.next.next:
            return head

        odd = head
        even = head.next
        begin_even = even
        last_odd = odd

        while even:
            if odd.next:
                odd.next = odd.next.next
                if odd.next:
                    last_odd = odd.next
                odd = odd.next
            else:
                odd.next = None

            if even.next:
                even.next = even.next.next
                even = even.next
            else:
                even.next = None
                break

        last_odd.next = begin_even

        return head


if __name__ == "__main__":
    n5 = ListNode(5)
    n4 = ListNode(4, n5)
    n3 = ListNode(3, n4)
    n2 = ListNode(2, n3)
    n1 = ListNode(1, n2)

    sol = Solution()

    head = sol.oddEvenList(n1)

    while head:
        print(head.val, end=" ")
        head = head.next

    print("")