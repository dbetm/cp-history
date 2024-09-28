# solved
# tags: binary tree, dfs, recursion


# This is the class of the input root. Do not edit it.
class BinaryTree:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


def depth_first_search_sum(node: BinaryTree, current_sum: int) -> None:
    if node.left == None and node.right == None:
        branch_sums.append(current_sum)
        return

    if node.left:
        current_sum += node.left.value
        depth_first_search_sum(node.left, current_sum)
        current_sum -= node.left.value

    if node.right:
        current_sum += node.right.value
        depth_first_search_sum(node.right, current_sum)
        current_sum -= node.right.value


def branchSums(root):
    global branch_sums
    branch_sums = list()
    depth_first_search_sum(root, root.value)

    return branch_sums
