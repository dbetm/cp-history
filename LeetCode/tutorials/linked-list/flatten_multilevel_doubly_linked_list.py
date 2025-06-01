"""
# Definition for a Node.
"""
from typing import Optional


class Node:
    def __init__(self, val, prev = None, next = None, child = None):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child


class Solution:
    def __init__(self):
        self.answer = None

    def dfs(self, node: Optional[Node]):
        if not node:
            return

        if not self.answer:
            new_node = Node(node.val)
            self.answer = new_node
        else:
            new_node = Node(node.val)
            new_node.prev = self.answer
            self.answer.next = new_node

        self.answer = self.answer.next if self.answer.next else self.answer

        self.dfs(node.child)

        return self.dfs(node.next)

    def flatten(self, head: Optional[Node]) -> Optional[Node]:
        self.dfs(head)

        head = self.answer

        while head and head.prev is not None:
            head = head.prev

        return head



if __name__ == "__main__":
    n1 = Node(val=1)
    n2 = Node(2)
    n3 = Node(3)
    n4 = Node(4)
    n5 = Node(5)
    n6 = Node(6)
    n7 = Node(7)
    n8 = Node(8)
    n9 = Node(9)
    n10 = Node(10)
    n11 = Node(11)
    n12 = Node(12)

    # level 1
        # next
    n1.next = n2
    n2.next = n3
    n3.next = n4
    n4.next = n5
    n5.next = n6
        # prev
    n6.prev = n5
    n5.prev = n4
    n4.prev = n3
    n3.prev = n2
    n2.prev = n1
        # children
    n3.child = n7

    # level 2
        # next
    n7.next = n8
    n8.next = n9
    n9.next = n10
        # prev
    n10.prev = n9
    n9.prev = n8
    n8.prev = n7
        # children
    n8.child = n11

    # level 3
        # next
    n11.next = n12
        # prev
    n12.prev = n11

    sol = Solution()

    ans = sol.flatten(n1)

    while ans:
        print(ans.val, end=" ")
        ans = ans.next
    
    print()