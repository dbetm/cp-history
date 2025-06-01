from typing import Optional


class Node:
    def __init__(self, val, next = None, random = None):
        self.val = val
        self.next = next
        self.random = random


class Solution:
    def copyRandomList(self, head: Optional[Node]) -> Optional[Node]:
        if not head:
            return head

        nodes_map = dict()
        copy = Node(head.val)
        new_head = copy

        nodes_map[id(head)] = copy

        tmp = head.next

        while tmp:
            new_node = Node(tmp.val)
            nodes_map[id(tmp)] = new_node

            copy.next = new_node
            copy = copy.next
            tmp = tmp.next

        tmp = head

        while tmp:
            if tmp.random:
                equivalent_copied = nodes_map[id(tmp)]

                equivalent_copied.random = nodes_map[id(tmp.random)]
            tmp = tmp.next

        return new_head


