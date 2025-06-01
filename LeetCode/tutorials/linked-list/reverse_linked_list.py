from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
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


if __name__ == "__main__":
    sol = Solution()

    node5 = ListNode(5)
    node4 = ListNode(4, node5)
    node3 = ListNode(3, node4)
    node2 = ListNode(2, node3)
    node1 = ListNode(1, node2)

    new_head = sol.reverseList(node1)

    while new_head:
        print(new_head.val, end=" ")
        new_head = new_head.next
    
    print()