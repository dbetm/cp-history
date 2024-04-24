# solved
# tags: heap, data-structures, binary-tree


"""The min heap is a kind of binary tree

The heap property refers to that every node must be smaller that all their children nodes 
(this for min heap), so always the root is the smallest value in the heap.

You represent a heap with a list or array. We use the indices to locate the corresponding nodes, so if

current_node = idx
left_child = idx*2 + 1
right_child = idx*2 + 2


or the equivalent to find the parent of a given node

parent_node = (idx - 1) // 2
"""

MAX_INT32 = 2**31 - 1

class MinHeap:
    """My solution"""
    def __init__(self, array):
        # Do not edit the line below.
        self.n = len(array)
        self.heap: list = self.buildHeap(array)

    def buildHeap(self, array) -> list:
        """
        Time: O(n * log2(n))
        Space: O(1)
        """
        self.heap = array
        for idx in range(self.n-1, -1, -1):
            if self.__is_parent(idx):
                print("[", array[idx], "is parent", "]")
                self.siftDown(idx)
                print(self.heap)
        # this is not great jeje
        return self.heap

    def __is_parent(self, idx) -> bool:
        return (idx*2 + 1) < self.n

    def __swap(self, idx1, idx2):
        print("swap", self.heap[idx1], self.heap[idx2])
        self.heap[idx1], self.heap[idx2] = self.heap[idx2], self.heap[idx1]

    def siftDown(self, idx):
        """
        Time: O(log2(n))
        Space: O(1)
        """
        while True:
            left_child_idx = idx*2 + 1
            right_child_idx = idx*2 + 2
            left_child = MAX_INT32
            right_child = MAX_INT32
            parent = self.heap[idx]

            print(f"{parent=}", f"{left_child_idx=}", f"{right_child_idx=}")

            if left_child_idx < self.n:
                left_child = self.heap[left_child_idx]
            if right_child_idx < self.n:
                right_child = self.heap[right_child_idx]
            
            if parent > left_child or parent > right_child:
                if left_child <= right_child:
                    self.__swap(left_child_idx, idx)
                    idx = left_child_idx
                elif left_child > right_child:
                    self.__swap(right_child_idx, idx)
                    idx = right_child_idx
                else:
                    break
            else:
                break

    def siftUp(self, idx):
        """
        Time: O(log2(n))
        Space: O(1)
        """
        while True:
            parent_idx = (idx - 1) // 2
            parent = self.heap[parent_idx]
            child = self.heap[idx]

            if parent > child:
                self.__swap(idx, parent_idx)
                idx = parent_idx
            else:
                break

            if idx == 0:
                break

    def peek(self):
        """
        Time: O(1)
        Space: O(1)
        """
        return self.heap[0]

    def remove(self):
        """
        Time: O(log2(n))
        Space: O(1)
        """
        self.__swap(0, -1)
        previous_root = self.heap.pop()
        self.n -= 1
        self.siftDown(0)

        return previous_root

    def insert(self, value):
        """
        Time: O(log2(n))
        Space: O(1)
        """
        self.heap.append(value)
        self.n += 1
        self.siftUp(self.n-1)

    def __str__(self) -> str:
        return ", ".join(map(str, self.heap))


if __name__ == "__main__":
    arr = list(map(int, input().split()))
    ops = int(input())

    min_heap = MinHeap(arr)
    print(min_heap)

    print("ops")

    for _ in range(ops):
        op = input()
        ans = eval(f"min_heap.{op}")

        print(op, ">>>> ", ans, " #### ", min_heap)
