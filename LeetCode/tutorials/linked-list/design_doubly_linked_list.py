from __future__ import annotations


class Node:
    def __init__(self, val: int, prev: Node = None, next: Node = None):
        self.val = val
        self.prev = prev
        self.next = next


class MyLinkedList:

    def print(self):
        tmp = self.head

        while tmp is not None:
            print(tmp.val, end=" ")
            tmp = tmp.next
        print()

    def __init__(self):
        self.head = None

    def get(self, index: int) -> int:
        tmp: Node = self.head

        cont = 0
        while tmp is not None:
            if cont == index:
                return tmp.val

            cont += 1
            tmp = tmp.next

        return -1

    def addAtHead(self, val: int) -> None:
        new_head = Node(val)

        if self.head is None:
            self.head = new_head
        else:
            self.head.prev = new_head
            new_head.next = self.head
            self.head = new_head

    def addAtTail(self, val: int) -> None:
        if self.head is None:
            return self.addAtHead(val)

        tmp = self.head
        new_tail = Node(val)

        while tmp.next:
            tmp = tmp.next

        new_tail.prev = tmp
        tmp.next = new_tail

    def addAtIndex(self, index: int, val: int) -> None:
        if index == 0:
            return self.addAtHead(val)

        new_node = Node(val)
        tmp: Node = self.head

        cont = 0
        is_inserted = False

        while tmp:
            if cont == index:
                prev = tmp.prev
                prev.next = new_node
                new_node.prev = prev
                new_node.next = tmp
                tmp.prev = new_node
                is_inserted = True
                break
            tmp = tmp.next
            cont += 1

        if not is_inserted and index == cont:
            return self.addAtTail(val)

    def deleteAtIndex(self, index: int) -> None:
        if self.head is None:
            return

        if index == 0:
            self.head = self.head.next
            if self.head:
                self.head.prev = None
            return

        tmp: Node = self.head

        cont = 0
        while tmp is not None:
            if cont == index:
                prev = tmp.prev
                next = tmp.next
                prev.next = next
                if next:
                    next.prev = prev
                break

            tmp = tmp.next
            cont += 1



if __name__ == "__main__":
    # Your MyLinkedList object will be instantiated and called as such:
    l = MyLinkedList()
    l.addAtHead(7)
    l.print()
    l.addAtHead(2)
    l.print()
    l.addAtHead(1)
    l.print()
    l.addAtIndex(3, 0)
    l.print()
    l.deleteAtIndex(2)
    l.print()
    l.addAtHead(6)
    l.print()
    l.addAtTail(4)
    l.print()
    print(l.get(4))
    l.addAtHead(4)
    l.print()
    l.addAtIndex(5, 0)
    l.print()
    l.addAtHead(6)
    l.print()