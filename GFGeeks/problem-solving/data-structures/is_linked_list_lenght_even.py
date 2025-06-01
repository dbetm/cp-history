# https://www.geeksforgeeks.org/problems/linked-list-length-even-or-odd/1
# tags: data-structures, linked-list

class Solution:
    # your task is to complete this function
    # function should return false if length is even
    # else return true
    def isLengthEven(self, head):
        cont = 0

        while head:
            cont += 1
            head = head.next

        return not cont & 1