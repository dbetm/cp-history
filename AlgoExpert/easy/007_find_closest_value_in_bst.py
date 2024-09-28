# solved
# tags: tags: bst, recursion

def findClosestValueInBst(tree, target):
    node = tree
    ans = -1
    diff = float("inf")

    while node != None:
        if abs(node.value - target) < diff:
            ans = node.value
            diff = abs(node.value - target)

            if diff == 0:
                break

        if target >= node.value:
            node = node.right
        else:
            node = node.left

    return ans


# This is the class of the input tree. Do not edit.
class BST:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
