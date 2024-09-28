# solved
# tags: dfs, binary tree


# This is the class of the input binary tree.
class BinaryTree:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


"""
         8
        /  \
       4    9
      / \
     2   5
"""

def dfs(node: BinaryTree, depth: int) -> None:
    global node_depths
    node_depths += depth
    
    if node.left == None and node.right == None:
        return

    if node.left:
        dfs(node.left, depth + 1)

    if node.right:
        dfs(node.right, depth + 1)


def nodeDepths(root):
    """My solution
    Time: O(n)
    Space: O(log n)
    """

    global node_depths
    node_depths = 0

    dfs(root, 0)

    return node_depths
    
