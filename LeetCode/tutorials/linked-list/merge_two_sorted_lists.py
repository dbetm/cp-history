import time

from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def print(self, head: ListNode):
        tmp = head

        while tmp:
            print(tmp.val, end=" ")
            tmp = tmp.next
        
        print()

    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        merged = None
        head = None

        if list1 and list2:
            if list1.val < list2.val:
                merged = list1
                head = merged
                list1 = list1.next
            elif list1.val == list2.val:
                merged = list1
                next_l1 = list1.next

                head = merged
                merged.next = list2
                merged = merged.next

                list1 = next_l1
                list2 = list2.next
            else:
                merged = list2
                head = merged
                list2 = list2.next
        elif list1:
            merged = list1
            head = merged
            list1 = list1.next
        elif list2:
            merged = list2
            head = merged
            list2 = list2.next
        
        while list1 or list2:
            if list1 and list2:
                # print("l1 and l2", list1.val, list2.val)
                # breakpoint()
                if list1.val < list2.val:
                    merged.next = list1
                    list1 = list1.next
                    merged = merged.next
                elif list1.val == list2.val:
                    merged.next = list1
                    list1 = list1.next
                    merged = merged.next

                    merged.next = list2
                    list2 = list2.next
                    merged = merged.next
                else:
                    merged.next = list2
                    list2 = list2.next
                    merged = merged.next
            elif list1:
                #print("l1", list1.val)
                merged.next = list1
                list1 = list1.next
                merged = merged.next
            else:
                #print("l2", list2.val)
                merged.next = list2
                list2 = list2.next
                merged = merged.next

        return head



if __name__ == "__main__":
    n4 = ListNode(4)
    n2 = ListNode(2, n4)
    l1 = ListNode(1, n2)

    n4 = ListNode(4)
    n3 = ListNode(3, n4)
    l2 = ListNode(1, n3)

    sol = Solution()
    sol.print(l1)
    sol.print(l2)
    head = sol.mergeTwoLists(l1, l2)

    while head:
        print(head.val, end=" ")
        head = head.next

    print("")