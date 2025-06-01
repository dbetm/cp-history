from __future__ import annotations


class Node:
    def __init__(self, val: int, next: Node = None):
        self.val = val
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
            new_head.next = self.head
            self.head = new_head

    def addAtTail(self, val: int) -> None:
        if self.head is None:
            return self.addAtHead(val)

        tmp = self.head
        new_tail = Node(val)

        while tmp.next is not None:
            tmp = tmp.next

        tmp.next = new_tail

    def addAtIndex(self, index: int, val: int) -> None:
        if index == 0:
            return self.addAtHead(val)

        new_node = Node(val)
        tmp: Node = self.head

        cont = 0
        while tmp is not None:
            if cont == (index-1):
                new_node.next = tmp.next
                tmp.next = new_node
                break
            tmp = tmp.next
            cont += 1

    def deleteAtIndex(self, index: int) -> None:
        if self.head is None:
            return

        if index == 0:
            self.head = self.head.next

        tmp: Node = self.head

        cont = 0
        while tmp is not None:
            if cont == (index-1):
                tmp.next = tmp.next.next if tmp.next else None
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